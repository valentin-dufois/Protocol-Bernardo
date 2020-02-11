//
//  Arena.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-12-07.
//

#include <limits>

#include "Arena.hpp"
#include "../Structs/Body.hpp"
#include "../Structs/Skeleton.hpp"

#include "glm/gtx/string_cast.hpp"

#define ERROR_THRESHOLD 10000
#define SPIKE_THRESHOLD 6000

namespace pb {

size_t Arena::count() const {
	return getSubset().size();
}

std::vector<Body *> Arena::getSubset() const {
	std::vector<Body *> bodies;

	_mutex->lock();

	for(std::pair<bodyUID, Body *> pair: *_bodies) {
		if(fitBody(pair.second))
			bodies.push_back(pair.second);
	}

	_mutex->unlock();

	return bodies;
}

Body * Arena::getBody(const bodyUID &uid) const {
	_mutex->lock();

	if(_bodies->find(uid) == _bodies->end()) {
		_mutex->unlock();
		return nullptr;
	}

	Body * body = _bodies->at(uid);

	if(fitBody(body)) {
		_mutex->unlock();
		return body;
	}

	_mutex->unlock();
	return nullptr;
}

bool Arena::fitBody(const Body * body) const {
	if(_devices.size() == 0)
		return true; // An empty list of devices UID means all are accepted

	// For all the devicesUID this body has
	for(pb::deviceUID deviceUID: body->devicesUID) {
		if(std::find(_devices.begin(), _devices.end(), deviceUID) != _devices.end())
			// The deviceUID is part of this arena, the body fit
			return true;
	}

	// The body doesnt fit
	return false;
}

double Arena::averageMoveSpeed() {
	double acc = 0;
	unsigned int jointsUsed = 0;

	Skeleton::JointID jointIDs[6] = {
		Skeleton::leftFoot,
		Skeleton::rightFoot,
		Skeleton::leftHand,
		Skeleton::rightHand,
		Skeleton::head,
		Skeleton::torso
	};

	std::vector<Body *> bodies = getSubset();

	if(bodies.size() == 0)
		return 0;

	for(Body * body: bodies) {
		if(body->skeletons.size() < 5)
			continue; // Ignore

//		std::list<Skeleton *>::iterator it = body->skeletons.begin();

		Skeleton * a = body->skeletons.front();
		Skeleton * b = body->skeletons.back();

		// Checking specified joints
		for(Skeleton::JointID jointID: jointIDs) {
			if(a->joints[jointID].positionConfidence == 0 ||
			   b->joints[jointID].positionConfidence == 0) {
				continue;
			}

			double dist = abs(glm::distance(a->joints[jointID].position, b->joints[jointID].position));

			if(dist < ERROR_THRESHOLD) {
				++jointsUsed;
				acc += dist;
			}
		}
	}

	if(jointsUsed == 0)
		return 0;

	constexpr double trackingEngineFreq = 5.0 / TRACKING_ENGINE_RUN_SPEED;

	const double avgMoveSpeed = (acc / double(jointsUsed)) / trackingEngineFreq;

	if(abs(avgMoveSpeed - _lastAvgMoveSpeed) < SPIKE_THRESHOLD) {
		_lastAvgMoveSpeed = avgMoveSpeed;
		return avgMoveSpeed;
	}

	return _lastAvgMoveSpeed;
}

std::tuple<Body *, double> Arena::mostActiveBody() {
	double max = 0, dist = 0;
	Body * fastestBody = nullptr;

	Skeleton::JointID jointIDs[5] = {
		Skeleton::leftFoot,
		Skeleton::rightFoot,
		Skeleton::leftHand,
		Skeleton::rightHand,
		Skeleton::torso
	};

	std::vector<Body *> bodies = getSubset();

	if(bodies.size() == 0)
		return {nullptr, 0};

	for(Body * body: bodies) {
		if(body->skeletons.size() < 5)
			continue; // Ignore

		//	std::list<Skeleton *>::iterator it = body->skeletons.begin();

		Skeleton * a = body->skeletons.front();
		Skeleton * b = body->skeletons.back();

		// Check specified joints
		for(Skeleton::JointID jointID: jointIDs) {
			if(a->joints[jointID].positionConfidence == 0 ||
			   b->joints[jointID].positionConfidence == 0) {
				continue;
			}

			dist = abs(glm::distance(a->joints[jointID].position, b->joints[jointID].position));

			if(dist > max && dist < ERROR_THRESHOLD) {
				max = dist;
				fastestBody = body;
			}
		}
	}

	constexpr double trackingEngineFreq = 5.0 / TRACKING_ENGINE_RUN_SPEED;

	const double maxMoveSpeed = max / trackingEngineFreq;

	if(abs(maxMoveSpeed - _lastMaxMoveSpeed) < SPIKE_THRESHOLD) {
		_lastMaxMoveSpeed = maxMoveSpeed;
		return {fastestBody, maxMoveSpeed};
	}

	return {fastestBody, _lastMaxMoveSpeed};
}

unsigned int Arena::movingBodiesCount() const {
	constexpr double threshold = 15;
	unsigned int movingBodies = 0;
	double dist;

	Skeleton::JointID jointIDs[5] = {
		Skeleton::leftFoot,
		Skeleton::rightFoot,
		Skeleton::leftHand,
		Skeleton::rightHand,
		Skeleton::torso
	};

	std::vector<Body *> bodies = getSubset();

	if(bodies.size() == 0)
		return 0;

	for(Body * body: bodies) {
		if(body->skeletons.size() < 5)
			continue; // Ignore

		//		std::list<Skeleton *>::iterator it = body->skeletons.begin();

		Skeleton * a = body->skeletons.front();
		Skeleton * b = body->skeletons.back();

		// Check specified joints
		for(Skeleton::JointID jointID: jointIDs) {
			if(a->joints[jointID].positionConfidence == 0 ||
			   b->joints[jointID].positionConfidence == 0) {
				continue;
			}

			dist = abs(glm::distance(a->joints[jointID].position, b->joints[jointID].position));

			if(dist >= threshold) {
				++movingBodies;
				break;
			}
		}
	}

	return movingBodies;
}

} /* ::pb */
