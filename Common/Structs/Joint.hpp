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
#include "../Network/Messages/messages.hpp"

namespace pb {

/**
 Represent a joint on a skeleton.
 */
struct Joint {
	// MARK: - Properties

    /** The current orientation of the joint */
    maths::vec3 orientation;
    
    /** The confidence of NiTE when giving the orientation */
    SCALAR orientationConfidence;
    
    /** The position in 3D space of the Joint */
	maths::vec3 position;

	/** The position in 2D space of the Joint */
	maths::vec2 position2D;
    
    /** The confidence of NiTE when giving the position */
    SCALAR positionConfidence;

	// MARK: - Constructors

	/// Default constructor
	Joint() {}

#ifdef PB_TRACKER

	/// This sconstructor allow for creating a `Joint` from NiTE joint.
	/// @param joint The NiTE joint to use
	/// @param tracker The NiTE tracker used to convert coordinates
	Joint(const nite::SkeletonJoint &joint, const nite::UserTracker &tracker) {
		orientation = maths::nQuatToVec3(joint.getOrientation());
		orientationConfidence = joint.getOrientationConfidence();

		// Joint coordinates are given in real world coordinates
		position = maths::P3FToVec3(joint.getPosition());
		position.x = position.x;
		positionConfidence = joint.getPositionConfidence();

		// Get their 2D values equivalent
		float x2D, y2D;

		tracker.convertJointCoordinatesToDepth(position.x, position.y, position.z, &x2D, &y2D);

		position2D.x = x2D;
		position2D.y = y2D;
	}

#endif /* PB_TRACKER */

	/// Build a Joint using the given message
	/// @param message The message holding the Joint's informations
	Joint(const network::messages::Joint &message) {
		orientation = maths::fromMessage(message.orientation());
		orientationConfidence = message.orientationconfidence();
		position = maths::fromMessage(message.position());
		position2D = maths::fromMessage(message.position2d());
		positionConfidence = message.positionconfidence();
	}

	// MARK: - Operators

	operator network::messages::Joint() const {
		network::messages::Joint message;

		// Fill in the message
		message.set_allocated_orientation(maths::asMessage(orientation));
		message.set_orientationconfidence(orientationConfidence);
		message.set_allocated_position(maths::asMessage(position));
		message.set_allocated_position2d(maths::asMessage(position2D));
		message.set_positionconfidence(positionConfidence);

		return message;
	}

	/// Add the given joint to the current one, multypliying it by its confidence for
	/// each value.
	/// @warning: This method is made to be used when doing a weighted mean of
	/// multiple skeletons
	Joint& operator += (const Joint &j2) {
		orientation += j2.orientation * j2.orientationConfidence;
		orientationConfidence += j2.orientationConfidence;

		position += j2.position * j2.positionConfidence;
		position2D += j2.position2D * j2.positionConfidence;
		positionConfidence += j2.positionConfidence;

		return *this;
	}

	/// Divide the positions and the orientation by the corresponding confidence,
	/// then divide each confidence by the given value.
	/// @warning: This method is made to be used when doing a weighted mean of
	/// multiple skeletons
	Joint operator / (const SCALAR &div) {
		Joint j;

		j.orientationConfidence = orientationConfidence / div;
		j.positionConfidence = positionConfidence / div;

		if(ceil(orientationConfidence) == 0) {
			// prevent division by 0
			orientation = maths::vec3(0, 0, 0);
		} else {
			j.orientation = orientation / orientationConfidence;
		}

		if(ceil(positionConfidence) == 0) {
			// prevent division by 0
			j.position = maths::vec3(0, 0, 0);
			j.position2D = maths::vec2(0, 0);
		} else {
			j.position = position / positionConfidence;
			j.position2D = position2D / positionConfidence;
		}

		return j;
	}

	Joint operator - (const Joint &j2) {
		Joint j;
		j.orientation = orientation - j2.orientation;
		j.orientationConfidence = orientationConfidence - j2.orientationConfidence;
		j.position = position - j2.position;
		j.position2D = position2D - j2.position2D;
		j.positionConfidence = positionConfidence - j2.positionConfidence;

		return j;
	}

};

} /* ::pb */

#endif /* Joint_h */
