//
//  TrackingEngine.cpp
//  pb-master
//
//  Created by Valentin Dufois on 2019-11-04.
//

#include "TrackingEngine.hpp"

#include "../../Common/Utils/maths.hpp"
#include "../../Common/Utils/Log.hpp"
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
		pthread_setname_np("pb.tracking-engine");

		runLoop();

		_executionThread->detach();
	});
}

void TrackingEngine::onBody(RawBody * rawBody) {
	_bodiesBufferMutex.lock();

	_bodiesBuffer.push_back(rawBody);

	_bodiesBufferMutex.unlock();
}

void TrackingEngine::runLoop() {
	std::chrono::time_point<std::chrono::system_clock> startPoint;

	while (_isTracking) {
		// Get the start time
		startPoint = std::chrono::system_clock::now();

		// Is there an active layout ?
		if(_layoutEngine->hasActiveLayout()) {
		   parseBodies();
		}

		// Cadence the loop
		cadenceLoop(std::chrono::system_clock::now() - startPoint);
	}
}

void TrackingEngine::parseBodies() {
	_bodiesBufferMutex.lock();

	for(RawBody * rawBody: _bodiesBuffer) {
		// We only handle tracked users
		if(rawBody->state != RawBody::State::tracked) {
			// remove reference to this rawBody in Bodies if needed
			removeRawBodyReference(rawBody);
			continue;
		}

		// Is this rawbody already matched to a body ?
		Body * body = getBodyFor(rawBody);

		if(body != nullptr) {
			// Yes, update it
			body->rawSkeletons[rawBody->deviceUID] = new Skeleton(rawBody->skeleton);
			// We store a copy of the skeleton as the rawbody will be destroyed in a bit
			continue;
		}

		// This rawbody is not already registered, let's see if its position matches the one of an exisiting user
		std::pair<Body *, SCALAR> closestBody = getClosestBodyFrom(rawBody);

		if(closestBody.first == nullptr || closestBody.second > TRACKING_ENGINE_MERGE_DISTANCE) {
			// Found no matching user, this is a new body
			_bodies.push_back(new Body(rawBody));

			continue;
		}

		closestBody.first->rawBodiesUID[rawBody->deviceUID] = rawBody->uid;
		closestBody.first->rawSkeletons[rawBody->deviceUID] = new Skeleton(rawBody->skeleton);
	}

	// Empty the buffer
	for(RawBody * rawBody: _bodiesBuffer) {
		delete rawBody;
	}
	_bodiesBuffer.clear();

	// Unlock
	_bodiesBufferMutex.unlock();

	//Calculate the average global position for each user
}


void TrackingEngine::cadenceLoop(const std::chrono::duration<double, std::milli> &workTime) {
	if(workTime.count() > (1.0/TRACKING_ENGINE_RUN_SPEED))
		return; // Last iteration took longer than one frame to complete, do not yield

	std::chrono::duration<double, std::milli> delta(1.0/TRACKING_ENGINE_RUN_SPEED - workTime.count());
	auto deltaMsDuration = std::chrono::duration_cast<std::chrono::milliseconds>(delta);

	// Temporary pause the thread
	std::this_thread::sleep_for(std::chrono::milliseconds(deltaMsDuration.count()));
}

Body * TrackingEngine::getBodyFor(const RawBody * rawbody) {
	std::vector<Body *>::iterator it = std::find_if(_bodies.begin(), _bodies.end(), [&] (Body * body) {
		if(body->rawBodiesUID.count(rawbody->deviceUID) == 0)
			return false;

		return body->rawBodiesUID[rawbody->deviceUID] == rawbody->uid;
	});

	return it == _bodies.end() ? nullptr : *it;
}

std::pair<Body *, SCALAR> TrackingEngine::getClosestBodyFrom(const RawBody * target) {
	// If no user, returns nothing
	if(_bodies.size() == 0)
		return std::pair(nullptr, 0);

	// Get the given target position in the global space
	vec3 targetTorso = _layoutEngine->globalCoordinates(target->skeleton.joints[::Skeleton::Joint::torso].position, target->deviceUID);

	std::vector<std::pair<Body *, SCALAR>> bodiesDistance;

	// Parse all the registered bodies and calculate the distance between them and the target
	for(Body * body: _bodies) {
		if(body->skeletons.size() == 0)
			continue;

		// Get the bodyt position in the global space
		vec3 bodyTorso = body->skeletons[body->skeletons.size()-1]->joints[Skeleton::torso].position;

		// Calculate and store the distance between this body and the target
		bodiesDistance.push_back(std::pair(body, glm::distance(bodyTorso, targetTorso)));
	}

	// Sort all the bodies by distance from the target
	std::sort(bodiesDistance.begin(),
			  bodiesDistance.end(),
			  [] (std::pair<Body *, SCALAR> a, std::pair<Body *, SCALAR> b) {
		return a.second < b.second;
	});

	// The first one is the closest one
	return bodiesDistance[0];
}

void TrackingEngine::removeRawBodyReference(const RawBody * rawbody) {
	Body * body = getBodyFor(rawbody);

	if(body == nullptr)
		return; // Nothing to do

	// Remove the rawbody reference from the body
	body->rawBodiesUID.erase(rawbody->deviceUID);

	// If the body has no more reference, we remove it completely
	if(body->rawBodiesUID.size() == 0) {
		std::remove(_bodies.begin(), _bodies.end(), body);
		delete body;
	}
}



