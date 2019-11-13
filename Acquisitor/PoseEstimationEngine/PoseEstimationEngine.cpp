//
//  PoseEstimationEngine.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#include "PoseEstimationEngine.hpp"
#include "../../Common/Utils/thread.hpp"

#include <chrono>

void PoseEstimationEngine::start() {
	if(_isRunning)
		return;

	_isRunning = true;

	// Start the run loop
	_executionThread = new std::thread([&] () {
		pb::setThreadName("pb.pose-estimation-engine");

		runLoop();

		_executionThread->detach();
	});

	// Create the parsers
	OpenNIParser * openNIParser = OpenNIParser::getInstance();
	openNIParser->onNewDevice = [&] (const Device * device) {
		onNewDevice(device);
	};

	_parsers.push_back(openNIParser);

	// Start the parsers
	for(Parser * p: _parsers) {
		p->start();
	}
}

std::vector<Device *> PoseEstimationEngine::getDevices() {
	std::vector<Device *> devices;

	for(Tracker * tracker: _trackers) {
		devices.push_back(tracker->getDevice());
	}

	return devices;
}

void PoseEstimationEngine::onNewDevice(const Device * device) {
	// We have a new device, let's build a tracker for it
	Tracker * tracker;

	switch (device->driver) {
		case Device::Driver::openni:
			tracker = new NiteTracker((OpenNIDevice *)device);
			break;
	}

	tracker->bodyHandler = [&] (RawBody * rawBody) {
		onRawBody(rawBody);
	};

	_trackers.push_back(tracker);
}

void PoseEstimationEngine::onRawBody(RawBody * rawBody) {
	_rawBodiesBufferMutex.lock();

	_rawBodies.insert(rawBody);

	_rawBodiesBufferMutex.unlock();
}

void PoseEstimationEngine::runLoop() {
	std::chrono::time_point<std::chrono::system_clock> startPoint;

	while (_isRunning) {
		// Get the start time
		startPoint = std::chrono::system_clock::now();

		if(onRawBodies) {
			_rawBodiesBufferMutex.lock();
			onRawBodies(_rawBodies);

			for(RawBody * rawBody: _rawBodies) {
				delete rawBody;
			}
			_rawBodies.clear();
			_rawBodiesBufferMutex.unlock();
		}
		
		// Cadence the loop
		pb::cadence(std::chrono::system_clock::now() - startPoint, POSE_ENGINE_RUN_SPEED);
	}
}

