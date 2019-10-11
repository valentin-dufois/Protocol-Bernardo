//
//  PoseEstimationEngine.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#include "PoseEstimationEngine.hpp"

void PoseEstimationEngine::start() {
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

void PoseEstimationEngine::onNewDevice(const Device * device) {
	// We have a new device, let's build a tracker for it
	Tracker * tracker;

	switch (device->driver) {
		case Device::Driver::openni:
			tracker = new NiteTracker((OpenNIDevice *)device);
			break;
	}

	tracker->bodyHandler = [&] (const Body * body) {
		if(onBody)
			onBody(body);
	};

	_trackers.push_back(tracker);
}
