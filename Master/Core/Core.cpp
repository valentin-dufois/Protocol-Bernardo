//
//  Core.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include "Core.hpp"

#include "../../Common/Utils/Log.hpp"

#include "Network/AcquisitorClient.hpp"
#include "../../Common/Structs/Body.hpp"

void Core::init() {
	_networkManager.setLayoutEngine(&_layoutEngine);
	_networkManager.onAcquisitor = [&] (AcquisitorClient * acquisitor) {
		onAcquisitor(acquisitor);
	};

	_networkManager.startActivities();
}

void Core::run() {
	// Main loop
	while(_isRunning) { }
}

void Core::onAcquisitor(AcquisitorClient * acquisitor) {
	acquisitor->onBody = [&] (const Body * body) {
		onBody(body);
	};
}

void Core::onBody(const Body * body) {
	LOG_DEBUG("Received body with ID " + std::to_string(body->uid) + " on device " + body->deviceUID);

	delete body;
}
