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

#include "Network/TrackerClient.hpp"

namespace pb {
namespace master {

void Core::init() {
	_networkManager.setLayoutEngine(&_layoutEngine);
	_networkManager.setTrackingEngine(&_trackingEngine);
	_networkManager.onTracker = [&] (TrackerClient * tracker) {
		onTracker(tracker);
	};

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

void Core::onTracker(TrackerClient * tracker) {
	// Link the tracker clients to the tracking engine
	tracker->onRawBody = [&] (RawBody * rawBody) {
		_trackingEngine.onRawBody(rawBody);
	};
}

void Core::onTrack(const std::map<pb::bodyUID, Body *> &bodies) {
	// Send the bodies to the terminal and the receiveers
	// Build the message
	messages::TrackedBodies * trackedBodies = new messages::TrackedBodies();

	for(std::pair<pb::deviceUID, Body *> bodyPair: bodies) {
		if(!bodyPair.second->hasSkeleton())
			continue;

		messages::Body * bodyMessage = trackedBodies->add_bodies();
		bodyMessage->CopyFrom((messages::Body)*bodyPair.second);

//		LOG_DEBUG(std::to_string(bodyPair.second->rawBodiesUID.size()));
	}

	if(_trackingEngine.canCalibrate()) {
		trackedBodies->set_allocated_calibrationvalues(_trackingEngine.getCalibrationValues());
	}

	messages::Datagram * datagram = makeDatagram(network::messages::Datagram_Type_TRACKED_BODIES, *trackedBodies);

	_networkManager.sendToReceivers(datagram);
	_networkManager.sendToTerminal(datagram);

	datagram->Clear();
	delete datagram;
	delete trackedBodies;
}

} /* ::master */
} /* ::pb */
