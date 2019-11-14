//
//  TrackingEngine.cpp
//  pb-master
//
//  Created by Valentin Dufois on 2019-11-04.
//

#include "TrackingEngine.hpp"

#include "../../Common/Utils/maths.hpp"
#include "../../Common/Utils/Log.hpp"
#include "../../Common/Utils/thread.hpp"
#include "../../Common/Structs/RawBody.hpp"
#include "../../Common/Structs/Body.hpp"

#include "../LayoutEngine/LayoutEngine.hpp"

#include <chrono>

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
		runLoop();

		_executionThread->detach();
	});
}

void TrackingEngine::onRawBody(RawBody * rawBody) {
	if(!_isTracking) {
		// Not tracking, do nothin, prevent leaks
		delete rawBody;
		return;
	}

	// Prevent other threads from accessing the buffer
	_bodiesBufferMutex.lock();

	// Append the two lists
	_bodiesBuffer.push_back(rawBody);

	// Unlock the buffer
	_bodiesBufferMutex.unlock();
}

void TrackingEngine::runLoop() {
	pb::setThreadName("pb.tracking-engine");

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
		pb::cadence(std::chrono::system_clock::now() - startPoint, TRACKING_ENGINE_RUN_SPEED);
	}
}

void TrackingEngine::trackBodies() {
	_bodiesBufferMutex.lock();

	// Empty buffer, do nothing
	if(_bodiesBuffer.size() == 0) {
		_bodiesBufferMutex.unlock();
		return;
	}

	// Parse the body buffer and fill in tracked bodies
	parseBodiesBuffer();


	// Unlock
	_bodiesBufferMutex.unlock();

	//Calculate the average global position for each body
	updateBodies();

	// Parse the bodies to prevent errors due to lack of precision from the tracking devices
	parseBodies();

	LOG_DEBUG("Tracking " + std::to_string(_bodies.size()) + " bodies");

	// Do we have a callback ?
	if(onCycleEnd) {
		onCycleEnd(_bodies);
	}
}

void TrackingEngine::parseBodiesBuffer() {

	for(RawBody * rawBody: _bodiesBuffer) {
		LOG_DEBUG("Parsing rawBody from " + rawBody->deviceUID);
		// Register device UID
		_devicesUID.insert(rawBody->deviceUID);

		// We only handle tracked users
		if(rawBody->state != RawBody::State::tracked) {
			// remove reference to this rawBody in Bodies if needed
			LOG_DEBUG("RawBody is not tracked");
			removeRawBodyReference(rawBody);
			continue;
		}

		// Convert the skeleton
		Skeleton * skeleton = _layoutEngine->inGlobalCoordinates(rawBody->skeleton, rawBody->deviceUID);

		// Is this rawbody already matched to a body ?
		Body * body = getBodyFor(rawBody);

		if(body != nullptr) {
			// Yes, update it
			LOG_DEBUG("RawBody matched with " + body->uid);
			body->rawSkeletons.push_back(skeleton);
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
	}

	// Empty the buffer
	clearBuffer();
}

void TrackingEngine::updateBodies() {
	for(std::pair<pb::bodyUID, Body *> bodyPair: _bodies) {
		bodyPair.second->updatePosition();
	}
}

void TrackingEngine::parseBodies() {
	if(_bodies.size() < 2)
		return; // Do nothing

	for(std::map<pb::bodyUID, Body *>::iterator it = _bodies.begin(); it != _bodies.end();) {
		Body * body = it->second;

		std::vector<std::pair<Body *, SCALAR>> bodiesDistance =  getClosestBodiesFrom(body->skeleton());

		if(bodiesDistance.size() == 0 || (bodiesDistance.size() == 1 && bodiesDistance[0].first == body)) {
			++it;
			continue;
		}

		// The closest body will usually be ourselves, so we should select the second one if this is the case
		std::pair<Body *, SCALAR> closest = bodiesDistance[0].first == body ? bodiesDistance[1] : bodiesDistance[0];

		if(closest.first == nullptr || closest.second >= TRACKING_ENGINE_MERGE_DISTANCE) {
			++it;
			continue; // The two bodies are not in merge distance, do nothing.
		}

		// The two bodies are really close, merge them. Merging occur with a one frame latency. We take the youngest body and put its references in the oldest one.
		LOG_DEBUG("MERGING");

		Body * youngest = body->frame < closest.first->frame ? body : closest.first;
		Body * oldest = body->frame >= closest.first->frame ? body : closest.first;

		for(std::pair<pb::deviceUID, pb::rawBodyUID> refs: youngest->rawBodiesUID) {
			oldest->rawBodiesUID[refs.first] = refs.second;
		}

		// Finally, mark the youngest as invalid
		youngest->isValid = false;
		++it;
	}

	// Cleanup
	for(std::map<pb::bodyUID, Body *>::iterator it = _bodies.begin(); it != _bodies.end();) {
		if(!it->second->isValid) {
			delete it->second;
			it = _bodies.erase(it);
			continue;
		}

		if(it->second->inactivityCount > 150) {
			delete it->second;
			it = _bodies.erase(it);
			continue;
		}

		++it;
	}
}

void TrackingEngine::clearBuffer() {
	// Empty the buffer
	for(RawBody * rawBody: _bodiesBuffer) {
		delete rawBody;
	}
	_bodiesBuffer.clear();
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
		vec3 bodyTorso = body->skeleton()->joints[Skeleton::torso].position;

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


void TrackingEngine::removeRawBodyReference(const RawBody * rawbody) {
	Body * body = getBodyFor(rawbody);

	if(body == nullptr)
		return; // Nothing to do

	// Remove the rawbody reference from the body
	body->rawBodiesUID.erase(rawbody->deviceUID);

	// If the body has no more reference, we remove it completely
	if(body->rawBodiesUID.size() == 0) {
		_bodies.erase(body->uid);
		delete body;
	}
}



