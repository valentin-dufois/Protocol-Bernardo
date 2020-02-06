//
//  Body.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-04.
//

#ifndef Body_h
#define Body_h

#include <string>
#include <list>
#include <unordered_set>

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "../common.hpp"
#include "../Network/Messages/messages.hpp"
#include "Skeleton.hpp"
#include "RawBody.hpp"

namespace pb {

// A body is a collection of one or more rawbodies that have been merge by the Tracking Engine using a layout. A Body has a current position as well as an history of positions
struct Body {

	// MARK: Properties

	/// Unique identifier for this body
	pb::bodyUID uid;

	/// The current frame of the user
	unsigned int frame = 0;

	/// The skeletons for this user in the global coordinates space. The first one being the oldest one, and the last one the actual one
	std::list<Skeleton *> skeletons;

	/// UIDs of all the devices currently tracking this body
	std::unordered_set<pb::deviceUID> devicesUID;

	/// List of RawBody uid paired with their device UID pair from which this body is taking data from
	std::map<pb::deviceUID, pb::rawBodyUID> rawBodiesUID;

	/// All the skeleton composing the current frame of the user
	/// This is used by the TrackingEngine.
	std::vector<Skeleton *> rawSkeletons;

	/// Tell if the body is valid. An invalid body does not have new meaningful skeletons.
	/// As of 2019-11-27, an invalid body will always be removed on the next frame.
	bool isValid = true;

	// MARK: - Constructors

	// Default constructor
	Body() = default;

	Body(RawBody * rawBody) {
		uid = boost::uuids::to_string(boost::uuids::random_generator()());
		rawBodiesUID[rawBody->deviceUID] = rawBody->uid;
		rawSkeletons.push_back(new Skeleton(rawBody->skeleton));
		devicesUID.insert(rawBody->deviceUID);
	}

	Body(const network::messages::PartialBody &body) {
		uid = body.uid();
		isValid = body.isvalid();
		frame = body.frame();
		devicesUID = {body.devicesuid().begin(), body.devicesuid().end()};
		skeletons.push_back(new Skeleton(body.skeleton()));
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

	/// How many cycles since the last time we received information on this body >?
	unsigned int inactivityCount = 0;

#ifdef PB_MASTER

	/// Calculate the weighted mean of all the raw skeletons matching the current body
	/// @returns True if the body has changed or false otherwise
	bool updatePosition() {
		if(!isValid)
			return true;

		// Is there any rawSkeleton to work with ?
		if(rawSkeletons.size() == 0) {
			++inactivityCount;

			if(inactivityCount > 15) {
				isValid = false;
				return true;
			}

			return false;
		}

		// Reset
		inactivityCount = 0;
		isValid = true;

		Skeleton skeleton;

		// Add all the rawSkeletons
		for(long unsigned int i = 0; i < rawSkeletons.size(); ++i) {
			// TODO: Make sure the skeletons are in the same direction (front back, check the hands)

			skeleton += *rawSkeletons[i];
		}

		// Divide them (weighted mean)
		Skeleton * newSkeleton = new Skeleton(skeleton / rawSkeletons.size());

		// If we already have a skeleton from before, we can use it to fill missing joints, if any
		if(hasSkeleton()) {

			// Check for missing joints
			for(int i = 0; i < newSkeleton->joints.size(); ++i) {
				if(newSkeleton->joints[i].positionConfidence != 0)
					continue; // Joint is ok

				// Joint is missing, did we have it before ?
				if(this->skeleton()->joints[i].positionConfidence == 0)
					continue; // Previous skeleton didn't had it either

				newSkeleton->joints[i] = this->skeleton()->joints[i];
			}
		}

		skeletons.push_back(newSkeleton);

		// Keep history size
		if(skeletons.size() > TRACKING_ENGINE_BODY_HISTORY_SIZE) {
			delete skeletons.front();
			skeletons.front() = nullptr;
			skeletons.erase(skeletons.begin());
		}

		// Increment the frame
		++frame;

		// Clear the raw skeletons
		clearRawSkeletons();

		return true;
	}

#endif /* PB_MASTER */

	void clearRawSkeletons() {
		// Clear the rawSkeletons
		for (Skeleton * skeleton: rawSkeletons) {
			delete skeleton;
			skeleton = nullptr;
		}

		rawSkeletons.clear();
	}

	// MARK: - Operators

	Body & insertPartial(const network::messages::PartialBody &partialBody)  {
		frame = partialBody.frame();

		skeletons.push_back(new Skeleton(partialBody.skeleton()));

		if(skeletons.size() > 5) {
			skeletons.pop_front();
		}

		inactivityCount = 0;

		return *this;
	}
};

} /* ::pb */

#endif /* Body_h */
