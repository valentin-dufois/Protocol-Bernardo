//
//  Core.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include <iostream>
#include <list>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Core.hpp"

#include "Network/AcquisitorClient.hpp"

#include "../../Common/common.hpp"
#include "../../Common/Messages/messages.hpp"
#include "../../Common/Utils/Log.hpp"
#include "../../Common/Structs/RawBody.hpp"
#include "../../Common/Structs/Body.hpp"

#include "../../Common/CommunicationEngine/Exchanges/Socket.hpp"

void Core::init() {
	_networkManager.setLayoutEngine(&_layoutEngine);
	_networkManager.setTrackingEngine(&_trackingEngine);
	_networkManager.onAcquisitor = [&] (AcquisitorClient * acquisitor) {
		onAcquisitor(acquisitor);
	};

	_networkManager.startActivities();

	// The tracking engine
	_trackingEngine.setLayoutEngine(&_layoutEngine);
	_trackingEngine.onCycleEnd = [&] (const std::map<pb::deviceUID, Body *> &bodies) {
		onTrack(bodies);
	};
	_trackingEngine.start();

	_broadcastServer.open();
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
	acquisitor->onRawBody = [&] (RawBody * rawBody) {
		_trackingEngine.onRawBody(rawBody);
	};
}

void Core::onTrack(const std::map<pb::bodyUID, Body *> &bodies) {
	// Send the bodies to the terminal
	// Build the message
	messages::TrackedBodies * trackedBodies = new messages::TrackedBodies();

	for(std::pair<pb::deviceUID, Body *> bodyPair: bodies) {
		if(!bodyPair.second->hasSkeleton())
			continue;

		messages::Body * bodyMessage = trackedBodies->add_bodies();
		bodyMessage->CopyFrom((messages::Body)*bodyPair.second);

		LOG_DEBUG(std::to_string(bodyPair.second->rawBodiesUID.size()));
	}

	messages::Datagram * datagram = messages::makeDatagram(messages::Datagram_Type_TRACKED_BODIES, *trackedBodies);

	_broadcastServer.sendToAllAsJSON(trackedBodies);
	_networkManager.sendToTerminal(datagram);

	delete trackedBodies;
}
