//
//  Core.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include <iostream>

#include "Core.hpp"

#include "Network/AcquisitorClient.hpp"

#include "../../Common/Messages/messages.hpp"
#include "../../Common/Utils/Log.hpp"
#include "../../Common/Structs/RawBody.hpp"
#include "../../Common/Structs/Body.hpp"

void Core::init() {
	_networkManager.setLayoutEngine(&_layoutEngine);
	_networkManager.setTrackingEngine(&_trackingEngine);
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
	// Link the acquisitor clients to the tracking engine
	acquisitor->onBody = [&] (RawBody * body) {
		_trackingEngine.onRawBody(body);
	};
}

void Core::onTrack(std::vector<Body *> bodies) {
	// Send the bodies to the terminal
	// Build the message

	messages::TrackedBodies * trackedBodies = new messages::TrackedBodies();

	for(Body * body: bodies) {
		messages::Body * bodyMessage = trackedBodies->add_bodies();
		bodyMessage->CopyFrom((messages::Body)*body);
	}

	_networkManager.sendToTerminal(trackedBodies);
}
