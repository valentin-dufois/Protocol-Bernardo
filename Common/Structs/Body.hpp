//
//  Body.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-01-25.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef Body_hpp
#define Body_hpp

#include "../Messages/messages.hpp"
#include "../Utils/maths.hpp"

#include "Skeleton.hpp"

/**
 Represent a body tracked by a device.
 A body is defined by a unique ID provided by the tracking engine, its state and a
 skeleton. depending on the state of the body, the content of the skeleton might be
 irrelevant.
 */
struct Body {
    /** The userID for the user, given by the tracking engine */
	short int uid;
    
    /** The skeleton of the user. Irrevelant if the user state isn't `tracked` */
	Skeleton skeleton;

	/// Defines the different states a user can take
	enum State: int {
		/** An error occured with the user. Any tracking on it has stop and will not
		 resume */
		error,

		/** The user has no skeleton */
		noSkeleton,

		/** The user is being tracked but is still calibrating.
		 A calibrating user has no skeleton. */
		calibrating,

		/** The user is being actively tracked and has a skeleton. */
		tracked,

		/** The user has gone missing. It will be completely removed and its ID may
		 be reassigned to a new user. A missing body may be tracked again is the user
		 is trackable again */
		missing,

		/**
		 The tracker has completely lost the body, and will no longer be tracked on
		 the next frame
		 */
		lost
	};

	/** The state of this user */
	State state;

	/** The device from which this body is coming from */
	std::string deviceUID;

	Body() = default;

	Body(const messages::Body &body) {
		uid = body.uid();
		skeleton = Skeleton(body.skeleton());

		switch(body.state()) {
			case messages::Body_State_error: 		state = error; 		break;
			case messages::Body_State_noSkeleton:	state = noSkeleton; 	break;
			case messages::Body_State_calibrating:	state = calibrating; 	break;
			case messages::Body_State_tracked: 	state = tracked; 	break;
			case messages::Body_State_missing:		state = missing;		break;
			case messages::Body_State_lost:		state = lost; 		break;
			default: break;
		}

		deviceUID = body.deviceuid();
	}

	// MARK: - Operators

	/// Casts the current body as a message for sending on the network
	operator messages::Body () const {
		messages::Body message;

		message.set_uid(uid);
		message.set_allocated_skeleton(skeleton);

		switch(state) {
			case State::error:
				message.set_state(messages::Body_State_error); break;
			case State::noSkeleton:
				message.set_state(messages::Body_State_noSkeleton); break;
			case State::calibrating:
				message.set_state(messages::Body_State_calibrating); break;
			case State::tracked:
				message.set_state(messages::Body_State_tracked); break;
			case State::missing:
				message.set_state(messages::Body_State_missing); break;
			case State::lost:
				message.set_state(messages::Body_State_lost); break;
		}

		message.set_deviceuid(deviceUID);

		return message;
	}
};

#endif /* User_hpp */
