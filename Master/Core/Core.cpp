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

void Core::trackingEngineUpdatedBody(TrackingEngine *, Body * body) {
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
	messages::Datagram * datagram = makeDatagram(messages::Datagram_Type_PARTIAL_BODY);
	protobuf::Any * anyMessage = new protobuf::Any();
	datagram->set_allocated_data(anyMessage);

	// Send each partial body one by one
	for(messages::PartialBody * message: _partialBodies) {
		anyMessage->PackFrom(*message);

		_networkManager.sendToReceivers(datagram);
		_networkManager.sendToTerminal(datagram);

		anyMessage->Clear();
		delete message;
	}

	datagram->Clear();
	_partialBodies.clear();

	delete datagram;

}

} /* ::master */
} /* ::pb */
