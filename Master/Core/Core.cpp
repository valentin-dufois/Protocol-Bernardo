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
	_trackingEngine.delegate = this;

	_trackingEngine.start();
}

void Core::run() {
	// Main loop
	while(_isRunning) {
		std::string input;
		std::cin >> input;
	}
}

void Core::
trackingEngineUpdatedBody(TrackingEngine *, Body * body) {
	// Prepare the message
	messages::PartialBody * message = new messages::PartialBody();
	message->set_uid(body->uid);
	message->set_frame(body->frame);
	message->set_isvalid(body->isValid);

	for(const pb::deviceUID &deviceUID: body->devicesUID) {
		message->add_devicesuid(deviceUID);
	}

	if(body->isValid)
		message->set_allocated_skeleton(*body->skeleton());

	_partialBodies.push_back(message);
}

void Core::trackingEngineFinishedCycle(TrackingEngine *) {
	// Prepare the receivers message
	messages::Datagram * receiversDatagram = makeDatagram(messages::Datagram_Type_PARTIAL_BODY);
	protobuf::Any * anyMessage = new protobuf::Any();
	receiversDatagram->set_allocated_data(anyMessage);

	// Prepare the terminal message
	messages::TrackedBodies * trackedBodies = new messages::TrackedBodies();

	// Send each partial body one by one, while preparing them for the terminal
	for(messages::PartialBody * message: _partialBodies) {
		anyMessage->PackFrom(*message);
		_networkManager.sendToReceivers(receiversDatagram);
		anyMessage->Clear();

		messages::PartialBody * bodyMessage = trackedBodies->add_bodies();
		bodyMessage->CopyFrom(*message);

		delete message;
	}

	// Attach calibration values if needed
	if(_trackingEngine.canCalibrate()) {
		trackedBodies->set_allocated_calibrationvalues(_trackingEngine.getCalibrationValues());
	}

	// Send to the terminal
	messages::Datagram * terminalDatagram = makeDatagram(network::messages::Datagram_Type_TRACKED_BODIES, *trackedBodies);
	_networkManager.sendToTerminal(terminalDatagram);

	// Clear
	_partialBodies.clear();
	receiversDatagram->Clear();
	terminalDatagram->Clear();
	delete receiversDatagram;
	delete terminalDatagram;
	delete trackedBodies;

}

} /* ::master */
} /* ::pb */
