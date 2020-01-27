//
//  TrackingEngine.cpp
//  pb-master
//
//  Created by Valentin Dufois on 2019-11-04.
//
#include <chrono>

#include "../../Common/Structs/RawBody.hpp"
#include "../../Common/Structs/Body.hpp"

#include "TrackingEngine.hpp"
#include "TrackingEngineDelegate.hpp"

#include "../LayoutEngine/LayoutEngine.hpp"

namespace pb {
namespace master {

void TrackingEngine::start() {
	if(_isTracking) {
		LOG_WARN("The tracking engine is already running");
	}

	if(_executionThread != nullptr && _executionThread->joinable()) {
		LOG_ERROR("The tracking engine execution thread should not exist at this point");
		return;
	}

	_isTracking = true;

	// Let's create and run the thread
	_executionThread = new std::thread([&] () {
		pb::thread::setName("pb.tracking-engine");

		runLoop();

		_isTracking = false;
	});
}

void TrackingEngine::onRawBody(RawBody * rawBody) {
	if(!_isTracking) {
		// Not tracking, do nothin, prevent leaks
		delete rawBody;
		return;
	}

	// Convert the body coordinates
	rawBody->skeleton = _layoutEngine->inGlobalCoordinates(rawBody->skeleton, rawBody->deviceUID);

	// Prevent other threads from accessing the buffer
	_bodiesBufferMutex.lock();

	// Append the two lists
	_bodiesBuffer.push_back(rawBody);

	// Unlock the buffer
	_bodiesBufferMutex.unlock();
}

void TrackingEngine::runLoop() {
	std::chrono::time_point<std::chrono::system_clock> startPoint;

	while (_isTracking) {
		// Get the start time
		startPoint = std::chrono::system_clock::now();

		// Is there an active layout ?
		if(_layoutEngine->hasActiveLayout()) {
			trackBodies();
		} else {
			_bodiesBufferMutex.lock();
			clearBuffer();
			_bodiesBufferMutex.unlock();
		}

		// Cadence the loop
		pb::thread::cadence(std::chrono::system_clock::now() - startPoint, TRACKING_ENGINE_RUN_SPEED);
	}
}

void TrackingEngine::trackBodies() {
	_bodiesBufferMutex.lock();

	// Parse the body buffer and fill in tracked bodies
	parseBodiesBuffer();

	// Unlock
	_bodiesBufferMutex.unlock();

	//
	updateCalibrationValues();

	// Calculate the average global position for each body
	updateBodies();

	if(!canCalibrate()) {
		// Parse the bodies to prevent errors due to lack of precision from the tracking devices
		parseBodies();
	}

	// Tell the delegate
	if(delegate != nullptr) {
		delegate->trackingEngineFinishedCycle(this);
	}

	// Remove invalid bodies
	cleanBodies();
}

void TrackingEngine::parseBodiesBuffer() {

	for(RawBody * rawBody: _bodiesBuffer) {
		if(rawBody == NULL)
			continue;

		// Register device UID
		_devicesUID.insert(rawBody->deviceUID);

		// We only handle tracked users
		if(rawBody->state != RawBody::State::tracked) {
			// remove reference to this rawBody in Bodies if needed
			removeRawBodyReference(rawBody);
			continue;
		}

		// Get the skeleton
		Skeleton * skeleton = new Skeleton(rawBody->skeleton);

		// Is this rawbody already matched to a body ?
		Body * body = getBodyFor(rawBody);

		if(body != nullptr) {
			body->rawSkeletons.push_back(skeleton);

			// Check if this body is used for calibration
			if(_calibrationDevices.first == rawBody->deviceUID) {
				if(_calibrationBodies.first != nullptr)
					delete _calibrationBodies.first;

				_calibrationBodies.first = new Skeleton(*skeleton);
			} else if(_calibrationDevices.second == rawBody->deviceUID) {
				if(_calibrationBodies.second != nullptr)
					delete _calibrationBodies.second;

				_calibrationBodies.second = new Skeleton(*skeleton);
			}

			continue;
		}

		// This rawbody is not already registered, let's see if its position matches the one of an exisiting user
		std::pair<Body *, SCALAR> closestBody = getClosestBodyFrom(skeleton);

		if(closestBody.first == nullptr || closestBody.second > TRACKING_ENGINE_MERGE_DISTANCE) {
			LOG_DEBUG("Tracking new body");
			// Found no matching user, this is a new body
			Body * body = new Body(rawBody);
			_bodies[body->uid] = body;

			continue;
		}

		LOG_DEBUG("Appending to existing body");
		closestBody.first->rawBodiesUID[rawBody->deviceUID] = rawBody->uid;
		closestBody.first->rawSkeletons.push_back(skeleton);

		closestBody.first->devicesUID.insert(rawBody->deviceUID);
	}

	// Empty the buffer
	clearBuffer();
}

void TrackingEngine::updateCalibrationValues() {
	if(!canCalibrate()) {
		return; // No calibration
	}

	// Compare the two skeletons
	Skeleton deltas = *_calibrationBodies.first - *_calibrationBodies.second;

	_calibrationValues.position = deltas.centerOfMass ;

	// Get the orientation delta using the shoulders
	maths::vec3 vecAngleA = _calibrationBodies.first->joints[Skeleton::leftShoulder].position - _calibrationBodies.first->joints[Skeleton::rightShoulder].position;

	maths::vec3 vecAngleB = _calibrationBodies.second->joints[Skeleton::leftShoulder].position - _calibrationBodies.second->joints[Skeleton::rightShoulder].position;

	// Calculate each angle
	_calibrationValues.angle.x = maths::rad2deg(glm::angle(glm::normalize(glm::vec2(vecAngleA.y, vecAngleA.z)), glm::normalize(glm::vec2(vecAngleB.y, vecAngleB.z))));

	_calibrationValues.angle.y = maths::rad2deg(glm::angle(glm::normalize(glm::vec2(vecAngleA.x, vecAngleA.z)), glm::normalize(glm::vec2(vecAngleB.x, vecAngleB.z))));

	_calibrationValues.angle.z = maths::rad2deg(glm::angle(glm::normalize(glm::vec2(vecAngleA.x, vecAngleA.y)), glm::normalize(glm::vec2(vecAngleB.x, vecAngleB.y))));
}

void TrackingEngine::updateBodies() {
	for(std::pair<pb::bodyUID, Body *> bodyPair: _bodies) {
		const bool updated = bodyPair.second->updatePosition();

		// Tell the delegate if the body has changed
		if(updated && delegate != nullptr)
			delegate->trackingEngineUpdatedBody(this, bodyPair.second);
	}
}

void TrackingEngine::parseBodies() {
	if(_bodies.size() < 2)
		return; // Do nothing

	for(std::map<pb::bodyUID, Body *>::iterator it = _bodies.begin(); it != _bodies.end(); ++it) {

		Body * body = it->second;

		if(!body->isValid)
			continue;

		// Check the body inactivity count
		if(body->inactivityCount > 15) {
			body->isValid = false;
			continue;
		}

		// Get all the bodies by distance
		std::vector<std::pair<Body *, SCALAR>> bodiesDistance =  getClosestBodiesFrom(body->skeleton());

		// Check we are not alone
		if(bodiesDistance.size() == 0 || (bodiesDistance.size() == 1 && bodiesDistance[0].first == body)) {
			continue;
		}

		// The closest body will usually be ourselves, so we should select the second one if this is the case
		std::pair<Body *, SCALAR> closest = bodiesDistance[0].first == body ? bodiesDistance[1] : bodiesDistance[0];

		if(closest.first == nullptr || closest.second >= TRACKING_ENGINE_MERGE_DISTANCE) {
			continue; // The two bodies are not in merge distance, do nothing.
		}

		// The two bodies are really close, merge them.
		// Merging occur with a one frame latency. We take the youngest body and put its references in the oldest one.
		Body * youngest = body->frame < closest.first->frame ? body : closest.first;
		Body * oldest = body->frame >= closest.first->frame ? body : closest.first;

		for(std::pair<pb::deviceUID, pb::rawBodyUID> refs: youngest->rawBodiesUID) {
			oldest->rawBodiesUID[refs.first] = refs.second;
			oldest->devicesUID.insert(refs.first);
		}

		// Finally, mark the youngest as invalid
		youngest->isValid = false;
	}
}

void TrackingEngine::clearBuffer() {
	// Empty the buffer
	for(RawBody * rawBody: _bodiesBuffer) {
		delete rawBody;
	}
	_bodiesBuffer.clear();
}

void TrackingEngine::cleanBodies() {
	for(auto it = _bodies.begin(); it != _bodies.end();) {
		if(it->second->isValid) {
			++it;
			continue;
		}

		// Remove invalid bodies
		delete it->second;
		it = _bodies.erase(it);
	}
}

Body * TrackingEngine::getBodyFor(const RawBody * rawbody) {
	std::map<pb::deviceUID, Body *>::iterator it = std::find_if(_bodies.begin(), _bodies.end(), [&] (std::pair<pb::deviceUID, Body *> bodyPair) {
		if(bodyPair.second->rawBodiesUID.count(rawbody->deviceUID) == 0)
			return false;

		return bodyPair.second->rawBodiesUID[rawbody->deviceUID] == rawbody->uid;
	});

	return it == _bodies.end() ? nullptr : it->second;
}

std::vector<std::pair<Body *, SCALAR>> TrackingEngine::getClosestBodiesFrom(const Skeleton * target) {
	// If no user, returns nothing
	if(_bodies.size() == 0)
		return std::vector<std::pair<Body *, SCALAR>>();

	std::vector<std::pair<Body *, SCALAR>> bodiesDistance;

	// Parse all the registered bodies and calculate the distance between them and the target
	for(std::pair<pb::deviceUID, Body *> bodyPair: _bodies) {
		Body * body = bodyPair.second;

		// Ignore invalid
		if(!body->isValid)
			continue;

		if(!body->hasSkeleton())
			continue;

		// Get the bodyt position in the global space
		maths::vec3 bodyTorso = body->skeleton()->joints[Skeleton::torso].position;

		// Calculate and store the distance between this body and the target
		bodiesDistance.push_back(std::pair(body,glm::distance(bodyTorso, target->joints[Skeleton::torso].position)));
	}

	// Sort all the bodies by distance from the target
	std::sort(bodiesDistance.begin(),
			  bodiesDistance.end(),
			  [] (std::pair<Body *, SCALAR> a, std::pair<Body *, SCALAR> b) {
		return a.second < b.second;
	});

	return bodiesDistance;
}

std::pair<Body *, SCALAR> TrackingEngine::getClosestBodyFrom(const Skeleton * target) {

	std::vector<std::pair<Body *, SCALAR>> bodiesDistance = getClosestBodiesFrom(target);

	// The first one is the closest one
	return bodiesDistance.size() > 0 ? bodiesDistance[0] : std::pair<Body *, SCALAR>(nullptr, 0);
}

TrackingEngine::~TrackingEngine() {
	clearBuffer();

	for(auto it = _bodies.begin(); it != _bodies.end();) {
		delete it->second;
	}
}


void TrackingEngine::removeRawBodyReference(const RawBody * rawbody) {
	Body * body = getBodyFor(rawbody);

	if(body == nullptr)
		return; // Nothing to do

	// Remove the rawbody reference from the body
	body->rawBodiesUID.erase(rawbody->deviceUID);
	body->devicesUID.erase(rawbody->deviceUID);

	// If the body has no more reference, we remove it completely
	if(body->devicesUID.size() == 0) {
		body->isValid = false;
	}
}

} /* ::master */
} /* ::pb */

