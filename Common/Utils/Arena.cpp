//
//  Arena.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-12-07.
//

#include "Arena.hpp"
#include "../Structs/Body.hpp"
#include "../Structs/Skeleton.hpp"

namespace pb {

unsigned long Arena::count() const {
	return getSubset().size();
}

std::vector<Body *> Arena::getSubset() const {
	std::vector<Body *> bodies;

	_mutex->lock();

	for(std::pair<bodyUID, Body *> pair: *_bodies) {
		if(_bounds.fit(pair.second->skeleton()->centerOfMass))
			bodies.push_back(pair.second);
	}

	_mutex->unlock();

	return bodies;
}

Body * Arena::getBody(const bodyUID &uid) const {
	if(_bodies->find(uid) == _bodies->end())
		return nullptr;

	Body * body = _bodies->at(uid);

	if(_bounds.fit(body->skeleton()->centerOfMass))
		return body;

	return nullptr;
}

double Arena::averageMoveSpeed() const {
	double acc = 0;
	double bodiesUsedCount = 0;

	std::vector<Body *> bodies = getSubset();

	if(bodies.size() == 0)
		return 0;

	for(Body * body: bodies) {
		if(body->skeletons.size() < 2)
			continue; // Ignore

		++bodiesUsedCount;

		std::list<Skeleton *>::iterator it = body->skeletons.begin();

		Skeleton * a = *it;
		Skeleton * b = *(++it);

		Skeleton::JointID jointIDs[6] = {
			Skeleton::leftFoot,
			Skeleton::rightFoot,
			Skeleton::leftHand,
			Skeleton::rightHand,
			Skeleton::head,
			Skeleton::torso
		};

		// Checking specified joints
		for(Skeleton::JointID jointID: jointIDs) {
			acc += abs(glm::distance(a->joints[jointID].position, b->joints[jointID].position));
		}
	}

	if(bodiesUsedCount == 0)
		return 0;

	constexpr double trackingEngineFreq = 1.0 / TRACKING_ENGINE_RUN_SPEED;

	return (acc / (bodiesUsedCount * 6.0)) / trackingEngineFreq;
}

std::tuple<Body *, double> Arena::mostActiveBody() const {
	double max = 0;
	Body * fastestBody = 0;
	double dist;

	std::vector<Body *> bodies = getSubset();

	if(bodies.size() == 0)
		return {nullptr, 0};

	for(Body * body: bodies) {
		if(body->skeletons.size() < 2)
			continue; // Ignore

		std::list<Skeleton *>::iterator it = body->skeletons.begin();

		Skeleton * a = *it;
		Skeleton * b = *(++it);

		Skeleton::JointID jointIDs[5] = {
			Skeleton::leftFoot,
			Skeleton::rightFoot,
			Skeleton::leftHand,
			Skeleton::rightHand,
			Skeleton::torso
		};

		// Checkint specified joints
		for(Skeleton::JointID jointID: jointIDs) {
			dist = abs(glm::distance(a->joints[jointID].position, b->joints[jointID].position));

			if(dist > max) {
				max = dist;
				fastestBody = body;
			}
		}
	}

	constexpr double trackingEngineFreq = 1.0 / TRACKING_ENGINE_RUN_SPEED;

	return {fastestBody, max / trackingEngineFreq};
}
} /* ::pb */
