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

		acc += abs(glm::distance(a->joints[Skeleton::leftFoot].position, b->joints[Skeleton::leftFoot].position));
		acc += abs(glm::distance(a->joints[Skeleton::rightFoot].position, b->joints[Skeleton::rightFoot].position));
		acc += abs(glm::distance(a->joints[Skeleton::leftHand].position, b->joints[Skeleton::leftHand].position));
		acc += abs(glm::distance(a->joints[Skeleton::rightHand].position, b->joints[Skeleton::rightHand].position));
		acc += abs(glm::distance(a->joints[Skeleton::head].position, b->joints[Skeleton::head].position));
		acc += abs(glm::distance(a->joints[Skeleton::torso].position, b->joints[Skeleton::torso].position));
	}

	constexpr double trackingEngineFreq = 1 / TRACKING_ENGINE_RUN_SPEED;

	return (acc / (bodiesUsedCount * 6)) / trackingEngineFreq;
}

std::tuple<Body *, double> Arena::mostActiveBody() const {
	double max = 0;
	Body * fastestBody = 0;
	double dist;

	std::vector<Body *> bodies = getSubset();

	if(bodies.size() == 0)
		return {nullptr, 0};

	for(Body * body: bodies) {
		std::list<Skeleton *>::iterator it = body->skeletons.begin();

		Skeleton * a = *it;
		Skeleton * b = *(++it);

		// Checking left foot
		dist = abs(glm::distance(a->joints[Skeleton::leftFoot].position, b->joints[Skeleton::leftFoot].position));

		if(dist > max) {
			max = dist;
			fastestBody = body;
		}

		// Checking right foot
		dist = abs(glm::distance(a->joints[Skeleton::rightFoot].position, b->joints[Skeleton::rightFoot].position));

		if(dist > max) {
			max = dist;
			fastestBody = body;
		}

		// Checking left hand
		dist = abs(glm::distance(a->joints[Skeleton::leftHand].position, b->joints[Skeleton::leftHand].position));

		if(dist > max) {
			max = dist;
			fastestBody = body;
		}

		// Checking right hand
		dist = abs(glm::distance(a->joints[Skeleton::rightHand].position, b->joints[Skeleton::rightHand].position));

		if(dist > max) {
			max = dist;
			fastestBody = body;
		}

		// Checking torso
		dist = abs(glm::distance(a->joints[Skeleton::torso].position, b->joints[Skeleton::torso].position));

		if(dist > max) {
			max = dist;
			fastestBody = body;
		}
	}

	constexpr double trackingEngineFreq = 1 / TRACKING_ENGINE_RUN_SPEED;

	return {fastestBody, max / trackingEngineFreq};
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



} /* ::pb */
