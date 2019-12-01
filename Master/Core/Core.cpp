//
//  Core.cpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include <iostream>
#include <list>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "../../Common/common.hpp"
#include "../../Common/Utils.hpp"
#include "../../Common/Structs/RawBody.hpp"
#include "../../Common/Structs/Body.hpp"

#include "Core.hpp"

namespace pb {
namespace master {

void Core::init() {
	_networkManager.setLayoutEngine(&_layoutEngine);
	_networkManager.setTrackingEngine(&_trackingEngine);

	_networkManager.startActivities();

	// The tracking engine
	_trackingEngine.setLayoutEngine(&_layoutEngine);
	_trackingEngine.onCycleEnd = [&] (const std::map<pb::deviceUID, Body *> &bodies) {
		onTrack(bodies);
	};

	_trackingEngine.start();
}

void Core::run() {
	// Main loop
	while(_isRunning) {
		std::string input;
		std::cin >> input;
	}
}

void Core::onTrack(const std::map<pb::bodyUID, Body *> &bodies) {
	// Send the bodies to the terminal and the receiveers
	// Build the message
	messages::TrackedBodies * trackedBodies = new messages::TrackedBodies();

	// Put all the tracked bodies in the message
	for(std::pair<pb::deviceUID, Body *> bodyPair: bodies) {
		messages::Body * bodyMessage = trackedBodies->add_bodies();
		bodyMessage->CopyFrom((messages::Body)*bodyPair.second);
	}

	// Attach calibration values if needed
	if(_trackingEngine.canCalibrate()) {
		trackedBodies->set_allocated_calibrationvalues(_trackingEngine.getCalibrationValues());
	}

	// Build the datagram
	messages::Datagram * datagram = makeDatagram(network::messages::Datagram_Type_TRACKED_BODIES, *trackedBodies);

	// Send to the receivers and the the terminal
	_networkManager.sendToReceivers(datagram);
	_networkManager.sendToTerminal(datagram);

	datagram->Clear();
	delete datagram;
	delete trackedBodies;
}

} /* ::master */
} /* ::pb */
