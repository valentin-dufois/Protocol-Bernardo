//
//  NiteTracker.cpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-18.
//

#include "NiteTracker.hpp"

#include "../../../Common/Network.hpp"
#include "../../../Common/Structs/RawBody.hpp"

namespace pb {
namespace tracker {

static const float kPi = 3.141592653589793238462643383280f;
static const float kPiDiv2 = 1.570796326794896619231321691640f;

NiteTracker::NiteTracker(OpenNIDevice * aDevice):
_device(aDevice)
{
	// Init the user tracker in a delay
	_tracker.create(_device->getDevice());
	_tracker.setSkeletonSmoothingFactor(.25f);
	_tracker.addNewFrameListener(this);
	LOG_INFO("Started pose tracking on a device");
}

void NiteTracker::onNewFrame(nite::UserTracker &) {
	// Retrieve the frame
	if(!_tracker.isValid())
		return;

	nite::UserTrackerFrameRef * userFrame = new nite::UserTrackerFrameRef();
	_tracker.readFrame(userFrame);

	// Ignore the frame if it is not valid
	if(!userFrame->isValid()) {
		return;
	}

	// Then, start working with the frame
	processFrame(userFrame);

	delete userFrame;
}

void NiteTracker::processFrame(nite::UserTrackerFrameRef * frame) {
	/// When Processing a frame, every detected nite users are parsed and formatted as a Body. Then, the body are passed on to an handler.


	// Get all the users on the frame
	const nite::Array<nite::UserData>& users = frame->getUsers();

	// Loop on all the users
	for(int i = 0;  i < users.getSize(); ++i) {
		const nite::UserData * userData = &users[i];

		// Create the body
		pb::RawBody * body = new pb::RawBody();
		body->uid = userData->getId();
		body->deviceUID = _device->getUID();

		// Handle new users
		if(userData->isNew()) {
			body->state = pb::RawBody::State::calibrating;

			// This is a new user, ask for skeleton tracking
			_tracker.startSkeletonTracking(body->uid);

			LOG_DEBUG("Found Body");

			// We just started tracking this user, there is nothing else to do here.
			// Just pass the body along and continue
			if(bodyHandler)
				bodyHandler(body);

			continue;
		}

		// Handle leaving users
		if(userData->isLost()) {
			// This user is not relevant anymore, stop tracking its skeleton and
			// de reference it.
			body->state = pb::RawBody::State::lost;
			_tracker.stopSkeletonTracking(body->uid);

			// Pass along the body and continue
			if(bodyHandler)
				bodyHandler(body);

			// Nothing else to do
			continue;
		}

		// Handle missing users
		if(!userData->isVisible()) {
			// User is not visible. Mark it as missing
			body->state = pb::RawBody::State::missing;

			// Pass along the body and continue
			if(bodyHandler)
				bodyHandler(body);

			// Nothing else to do
			continue;
		}

		// Is this user's skeleton still calibrating ?
		if(userData->getSkeleton().getState() == nite::SkeletonState::SKELETON_CALIBRATING) {
			body->state = pb::RawBody::State::calibrating;

			// Pass along the body and continue
			if(bodyHandler)
				bodyHandler(body);

			// Nothing else to do
			continue;
		}

		// Is this user's skeleton errored ?
		if(userData->getSkeleton().getState() != nite::SkeletonState::SKELETON_TRACKED) {
			body->state = pb::RawBody::State::error;

			// Pass along the body and continue
			if(bodyHandler)
				bodyHandler(body);

			// Nothing else to do
			continue;
		}

		// User is ok, update its skeleton
		body->state = pb::RawBody::State::tracked;

//		LOG_DEBUG("Tracking Body");

		// If we are here, it means the user is being actively tracked. Let's update its structure.
		body->skeleton.centerOfMass = pb::maths::P3FToVec3(userData->getCenterOfMass());

		// Update the body's skeleton and all its joint coordinates
		pb::Skeleton * skeleton = &body->skeleton;
		const nite::Skeleton * niteSkeleton = &(userData->getSkeleton());

		skeleton->set(pb::Skeleton::JointID::head, Joint(niteSkeleton->getJoint(nite::JOINT_HEAD), _tracker));
		skeleton->set(pb::Skeleton::JointID::neck, Joint(niteSkeleton->getJoint(nite::JOINT_NECK), _tracker));
		skeleton->set(pb::Skeleton::JointID::leftShoulder, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_SHOULDER), _tracker));
		skeleton->set(pb::Skeleton::JointID::rightShoulder, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_SHOULDER), _tracker));
		skeleton->set(pb::Skeleton::JointID::leftElbow, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_ELBOW), _tracker));
		skeleton->set(pb::Skeleton::JointID::rightElbow, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_ELBOW), _tracker));
		skeleton->set(pb::Skeleton::JointID::leftHand, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_HAND), _tracker));
		skeleton->set(pb::Skeleton::JointID::rightHand, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_HAND), _tracker));
		skeleton->set(pb::Skeleton::JointID::torso, Joint(niteSkeleton->getJoint(nite::JOINT_TORSO), _tracker));
		skeleton->set(pb::Skeleton::JointID::leftHip, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_HIP), _tracker));
		skeleton->set(pb::Skeleton::JointID::rightHip, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_HIP), _tracker));
		skeleton->set(pb::Skeleton::JointID::leftKnee, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_KNEE), _tracker));
		skeleton->set(pb::Skeleton::JointID::rightKnee, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_KNEE), _tracker));
		skeleton->set(pb::Skeleton::JointID::leftFoot, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_FOOT), _tracker));
		skeleton->set(pb::Skeleton::JointID::rightFoot, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_FOOT), _tracker));
		
		// LOG_DEBUG("Skeleton Tracked");

		// Pass along the body
		if(bodyHandler)
			bodyHandler(body);
	}
}

NiteTracker::~NiteTracker() {
	_tracker.destroy();

	delete _device;
	_device = nullptr;
}

} /* ::tracker */
} /* ::pb */
