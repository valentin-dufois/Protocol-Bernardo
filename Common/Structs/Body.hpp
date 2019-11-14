//
//  Body.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-04.
//

#ifndef Body_h
#define Body_h

#include "../common.hpp"
#include "../Messages/messages.hpp"
#include "Skeleton.hpp"
#include "RawBody.hpp"

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <string>
#include <list>

// A body is a collection of one or more rawbodies that have been merge by the Tracking Engine using a layout. A Body has a current position as well as an history of positions
struct Body {

	// MARK: Properties

	/// Unique identifier for this body
	pb::bodyUID uid;

	/// The current frame of the user
	unsigned int frame = 0;

	/// The skeletons for this user in the global coordinates space. The first one being the oldest one, and the last one the actual one
	std::list<Skeleton *> skeletons;

	/// The list of device UID, RawBody uid pair from which this body is taking data from
	std::map<pb::deviceUID, pb::rawBodyUID> rawBodiesUID;

	/// All the skeleton composing the current frame of the user
	/// This is used by the TrackingEngine.
	std::vector<Skeleton *> rawSkeletons;

	bool isValid = true;

	unsigned int inactivityCount = 0;

	// MARK: - Constructors

	// Default constructor
	Body() = default;

	Body(RawBody * rawBody) {
		uid = boost::uuids::to_string(boost::uuids::random_generator()());
		rawBodiesUID[rawBody->deviceUID] = rawBody->uid;
		rawSkeletons.push_back(new Skeleton(rawBody->skeleton));
	}

	~Body() {
		for(Skeleton * skeleton: skeletons) {
			delete skeleton;
		}

		clearRawSkeletons();
	}

	// MARK: - Accessors

	inline bool hasSkeleton() { return skeletons.size() > 0; }

	inline Skeleton * skeleton() { return skeletons.back(); }

	// MARK: - Manipulations

	/// Calculate the weighted mean of all the raw skeletons matching the current body
	void updatePosition() {

		// Is there any rawSkeleton to work with ?
		if(rawSkeletons.size() == 0) {
			++inactivityCount;
			return;
		}

		inactivityCount = 0;

		Skeleton skeleton;

		// Add all the rawSkeletons
		for(int i = 0; i < rawSkeletons.size(); ++i) {
			// TODO: Make sure the skeletons are in the same direction (front back, check the hands)

			skeleton += *rawSkeletons[i];
		}

		// Divide them (weighted mean)
		skeletons.push_back(new Skeleton(skeleton / rawSkeletons.size()));

		// Keep history size
		if(skeletons.size() > TRACKING_ENGINE_BODY_HISTORY_SIZE) {
			delete skeletons.front();
			skeletons.erase(skeletons.begin());
		}

		// Increment the frame
		++frame;

		// Clear the raw skeletons
		clearRawSkeletons();
	}

	void clearRawSkeletons() {
		// Clear the rawSkeletons
		for (Skeleton * skeleton: rawSkeletons) {
			delete skeleton;
		}

		rawSkeletons.clear();
	}

	// MARK: - Operators

	operator messages::Body () const {
		messages::Body message;
		message.set_uid(uid);
		message.set_frame(frame);

		// Convert the skeletons
		for(Skeleton * s: skeletons) {
			messages::Skeleton * skeletonMessage = message.add_skeletons();
			skeletonMessage->CopyFrom((messages::Skeleton)*s);
		}

		return message;
	}
};

#endif /* Body_h */
