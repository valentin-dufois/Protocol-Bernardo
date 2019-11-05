//
//  Core.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include <iostream>

#include "Core.hpp"

#include "../../Common/Utils/Log.hpp"

#include "Network/AcquisitorClient.hpp"
#include "../../Common/Structs/RawBody.hpp"

void Core::init() {
	_networkManager.setLayoutEngine(&_layoutEngine);
	_networkManager.onAcquisitor = [&] (AcquisitorClient * acquisitor) {
		onAcquisitor(acquisitor);
	};

	_networkManager.startActivities();

	// The tracking engine
	_trackingEngine.setLayoutEngine(&_layoutEngine);
	_trackingEngine.start();
}

void Core::run() {
	// Main loop
	while(_isRunning) {
		std::string input;
		std::cin >> input;
	}
}

void Core::onAcquisitor(AcquisitorClient * acquisitor) {
	acquisitor->onBody = [&] (const RawBody * body) {
		onBody(body);
	};
}

void Core::onBody(const RawBody * body) {
	LOG_DEBUG("Received body with ID " + std::to_string(body->uid) + " on device " + body->deviceUID);

	// Relay the body

	delete body;
}
