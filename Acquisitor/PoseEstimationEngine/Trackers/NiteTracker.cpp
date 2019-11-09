//
//  NiteTracker.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-18.
//

#include "NiteTracker.hpp"

#include "../../../Common/CommunicationEngine/CommunicationEngine.hpp"

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

	LOG_DEBUG("Processing frame " + std::to_string(users.getSize()));

	// Loop on all the users
	for(int i = 0;  i < users.getSize(); ++i) {
		const nite::UserData * userData = &users[i];

		// Create the body
		RawBody * body = new RawBody();
		body->uid = userData->getId();
		body->deviceUID = _device->getUID();

		// Handle new users
		if(userData->isNew()) {
			body->state = RawBody::State::calibrating;

			// This is a new user, ask for skeleton tracking
			_tracker.startSkeletonTracking(body->uid);

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
			body->state = RawBody::State::lost;
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
			body->state = RawBody::State::missing;

			// Pass along the body and continue
			if(bodyHandler)
				bodyHandler(body);

			// Nothing else to do
			continue;
		}

		// Is this user's skeleton still calibrating ?
		if(userData->getSkeleton().getState() == nite::SkeletonState::SKELETON_CALIBRATING) {
			body->state = RawBody::State::calibrating;

			// Pass along the body and continue
			if(bodyHandler)
				bodyHandler(body);

			// Nothing else to do
			continue;
		}

		// Is this user's skeleton errored ?
		if(userData->getSkeleton().getState() != nite::SkeletonState::SKELETON_TRACKED) {
			body->state = RawBody::State::error;

			// Pass along the body and continue
			if(bodyHandler)
				bodyHandler(body);

			// Nothing else to do
			continue;
		}

		// User is ok, update its skeleton
		body->state = RawBody::State::tracked;

		// If we are here, it means the user is being actively tracked. Let's update its structure.
		body->skeleton.centerOfMass = maths::P3FToVec3(userData->getCenterOfMass());

		// Update the body's skeleton and all its joint coordinates
		Skeleton * skeleton = &body->skeleton;
		const nite::Skeleton * niteSkeleton = &(userData->getSkeleton());

		auto truc = skeleton[Skeleton::Joint::head];

		skeleton->set(Skeleton::Joint::head, Joint(niteSkeleton->getJoint(nite::JOINT_HEAD), _tracker));
		skeleton->set(Skeleton::Joint::neck, Joint(niteSkeleton->getJoint(nite::JOINT_NECK), _tracker));
		skeleton->set(Skeleton::Joint::leftShoulder, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_SHOULDER), _tracker));
		skeleton->set(Skeleton::Joint::rightShoulder, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_SHOULDER), _tracker));
		skeleton->set(Skeleton::Joint::leftElbow, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_ELBOW), _tracker));
		skeleton->set(Skeleton::Joint::rightElbow, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_ELBOW), _tracker));
		skeleton->set(Skeleton::Joint::leftHand, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_HAND), _tracker));
		skeleton->set(Skeleton::Joint::rightHand, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_HAND), _tracker));
		skeleton->set(Skeleton::Joint::torso, Joint(niteSkeleton->getJoint(nite::JOINT_TORSO), _tracker));
		skeleton->set(Skeleton::Joint::leftHip, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_HIP), _tracker));
		skeleton->set(Skeleton::Joint::rightHip, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_HIP), _tracker));
		skeleton->set(Skeleton::Joint::leftKnee, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_KNEE), _tracker));
		skeleton->set(Skeleton::Joint::rightKnee, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_KNEE), _tracker));
		skeleton->set(Skeleton::Joint::leftFoot, Joint(niteSkeleton->getJoint(nite::JOINT_LEFT_FOOT), _tracker));
		skeleton->set(Skeleton::Joint::rightFoot, Joint(niteSkeleton->getJoint(nite::JOINT_RIGHT_FOOT), _tracker));

		// Pass along the body
		if(bodyHandler)
			bodyHandler(body);
	}
}

NiteTracker::~NiteTracker() {
	delete _device;
	_device = nullptr;
}

