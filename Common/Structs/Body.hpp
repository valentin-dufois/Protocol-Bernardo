//
//  Body.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-04.
//

#ifndef Body_h
#define Body_h

#include "../common.hpp"
#include "Skeleton.hpp"
#include "RawBody.hpp"

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <string>

// A body is a collection of one or more rawbodies that have been merge by the Tracking Engine using a layout. A Body has a current position as well as an history of positions
struct Body {
	/// Unique identifier for this body
	pb::bodyUID uid;

	/// The skeletons for this user in the global coordinates space. The first one being the oldest one, and the last one the actual one
	std::vector<Skeleton *> skeletons;

	/// The list of device UID, RawBody uid pair from which this body is taking data from
	std::map<pb::deviceUID, pb::rawBodyUID> rawBodiesUID;

	/// All the skeleton composing the current frame of the user
	/// This is used by the TrackingEngine.
	std::map<pb::deviceUID, Skeleton *> rawSkeletons;


	// Default constructor
	Body() = default;

	Body(RawBody * rawBody) {
		uid = boost::uuids::to_string(boost::uuids::random_generator()());
		rawBodiesUID[rawBody->deviceUID] = rawBody->uid;
		rawSkeletons[rawBody->deviceUID] = new Skeleton(rawBody->skeleton);
	}

	~Body() {
		for(Skeleton * skeleton: skeletons) {
			delete skeleton;
		}

		for (auto& [deviceUID, skeleton]: rawSkeletons) {
			delete skeleton;
		}
	}
};

#endif /* Body_h */
