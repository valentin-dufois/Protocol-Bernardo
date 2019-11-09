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

void TrackingEngine::onRawBody(RawBody * rawBody) {
	if(!_isTracking) {
		// Not tracking, do nothin, prevent leaks
		delete rawBody;
	}

	// Prevent other threads from accessing the buffer
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
			trackBodies();
		} else {
			clearBuffer();
		}

		// Cadence the loop
		cadenceLoop(std::chrono::system_clock::now() - startPoint);
	}
}

void TrackingEngine::trackBodies() {
	// Parse the body buffer and fill in tracked bodies
	parseBodiesBuffer();

	//Calculate the average global position for each body
	updateBodies();

	// Parse the bodies to prevent errors due to lack of precision from the tracking devices
	parseBodies();

	// Do we have a callback ?
	if(onCycleEnd) {
		onCycleEnd(_bodies);
	}
}

void TrackingEngine::parseBodiesBuffer() {
	_bodiesBufferMutex.lock();

	for(RawBody * rawBody: _bodiesBuffer) {
		// We only handle tracked users
		if(rawBody->state != RawBody::State::tracked) {
			// remove reference to this rawBody in Bodies if needed
			removeRawBodyReference(rawBody);
			continue;
		}

		// Convert the skeleton
		Skeleton * skeleton = _layoutEngine->inGlobalCoordinates(rawBody->skeleton, rawBody->deviceUID);

		// Is this rawbody already matched to a body ?
		Body * body = getBodyFor(rawBody);

		if(body != nullptr) {
			// Yes, update it
			body->rawSkeletons[rawBody->deviceUID] = skeleton;
			continue;
		}

		// This rawbody is not already registered, let's see if its position matches the one of an exisiting user
		std::pair<Body *, SCALAR> closestBody = getClosestBodyFrom(skeleton);

		if(closestBody.first == nullptr || closestBody.second > TRACKING_ENGINE_MERGE_DISTANCE) {
			// Found no matching user, this is a new body
			_bodies.push_back(new Body(rawBody));

			continue;
		}

		closestBody.first->rawBodiesUID[rawBody->deviceUID] = rawBody->uid;
		closestBody.first->rawSkeletons[rawBody->deviceUID] = skeleton;
	}

	// Empty the buffer
	clearBuffer();

	// Unlock
	_bodiesBufferMutex.unlock();
}

void TrackingEngine::updateBodies() {
	for(Body * body: _bodies) {
		body->updatePosition();
	}
}

void TrackingEngine::parseBodies() {
	if(_bodies.size() < 2)
		return; // Do nothing

	for(Body * body: _bodies) {
		std::vector<std::pair<Body *, SCALAR>> bodiesDistance =  getClosestBodiesFrom(body->skeleton());

		// The closest body will usually be ourselves, so we should select the second one if this is the case
		std::pair<Body *, SCALAR> closest = bodiesDistance[0].first == body ? bodiesDistance[1] : bodiesDistance[0];

		if(closest.second >= TRACKING_ENGINE_MERGE_DISTANCE)
			continue; // The two bodies are not in merge distance, do nothing.

		// The two bodies are really close, merge them. Merging occur with a one frame latency. We take the youngest body and put its references in the oldest one.

		Body * youngest = body->frame < closest.first->frame ? body : closest.first;
		Body * oldest = body->frame >= closest.first->frame ? body : closest.first;

		for(std::pair<pb::deviceUID, pb::rawBodyUID> refs: youngest->rawBodiesUID) {
			oldest->rawBodiesUID[refs.first] = refs.second;
		}

		// Finally, remove the youngest user
		std::remove(_bodies.begin(), _bodies.end(), youngest);
	}
}

void TrackingEngine::clearBuffer() {
	// Empty the buffer
	for(RawBody * rawBody: _bodiesBuffer) {
		delete rawBody;
	}
	_bodiesBuffer.clear();
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



std::vector<std::pair<Body *, SCALAR>> TrackingEngine::getClosestBodiesFrom(const Skeleton * target) {
	// If no user, returns nothing
	if(_bodies.size() == 0)
		return std::vector<std::pair<Body *, SCALAR>>();

	std::vector<std::pair<Body *, SCALAR>> bodiesDistance;

	// Parse all the registered bodies and calculate the distance between them and the target
	for(Body * body: _bodies) {
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
		std::remove(_bodies.begin(), _bodies.end(), body);
		delete body;
	}
}



