//
//  Joint.h
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-01-25.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef Joint_h
#define Joint_h

#include "../Utils/maths.hpp"
#include "../Messages/messages.hpp"

/**
 Represent a joint on a skeleton.
 */
struct Joint {
	// MARK: - Properties

    /** The current orientation of the joint */
    vec4 orientation;
    
    /** The confidence of NiTE when giving the orientation */
    SCALAR orientationConfidence;
    
    /** The position in 3D space of the Joint */
	vec3 position;

	/** The position in 2D space of the Joint */
	vec2 position2D;
    
    /** The confidence of NiTE when giving the position */
    SCALAR positionConfidence;

	// MARK: - Constructors

	/// Default constructor
	Joint() {}

#ifdef MACHINE_ACQUISITOR

	/// This sconstructor allow for creating a `Joint` from NiTE joint.
	/// @param joint The NiTE joint to use
	/// @param tracker The NiTE tracker used to convert coordinates
	Joint(const nite::SkeletonJoint &joint, const nite::UserTracker &tracker) {
		orientation = maths::nQuatToVec4(joint.getOrientation());
		orientationConfidence = joint.getOrientationConfidence();

		// Joint coordinates are given in real world coordinates
		position = maths::P3FToVec3(joint.getPosition());
		positionConfidence = joint.getPositionConfidence();

		// Get their 2D values equivalent
		float x2D, y2D;

		tracker.convertJointCoordinatesToDepth(position.x, position.y, position.z, &x2D, &y2D);

		position2D.x = x2D;
		position2D.y = y2D;
	}

#endif /* MACHINE_ACQUISITOR */

	/// Build a Joint using the given message
	/// @param message The message holding the Joint's informations
	Joint(const messages::Joint &message) {
		orientation = maths::fromMessage(message.orientation());
		orientationConfidence = message.orientationconfidence();
		position = maths::fromMessage(message.position());
		position2D = maths::fromMessage(message.position2d());
		positionConfidence = message.positionconfidence();
	}

	// MARK: - Conversions

	operator messages::Joint() const {
		messages::Joint message;

		// Fill in the message
		message.set_allocated_orientation(maths::asMessage(orientation));
		message.set_orientationconfidence(orientationConfidence);
		message.set_allocated_position(maths::asMessage(position));
		message.set_allocated_position2d(maths::asMessage(position2D));
		message.set_positionconfidence(positionConfidence);

		return message;
	}

};

#endif /* Joint_h */
