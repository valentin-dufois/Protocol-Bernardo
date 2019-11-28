
//
//  TrackerClient.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-27.
//

#include "TrackerClient.hpp"

#include "../../../Common/Structs/RawBody.hpp"

namespace pb {
namespace master {

TrackerClient::TrackerClient() {
	_socket.delegate = this;
}

void TrackerClient::socketDidOpen(Socket *) {
	LOG_INFO("Connection opened");

	_socket.send(makeDatagram(messages::Datagram_Type_ACQ_GET_BODY_STREAM));

	if(onConnected)
		onConnected(_socket.getRemote());
}

void TrackerClient::socketDidReceive(Socket *, messages::Datagram * datagram) {
	// LOG_DEBUG("Received a datagram");

	messages::Datagram_Type datagramType = datagram->type();

	// Dispatch based on the datagram type
	switch (datagramType) {
		// Tracker
		case messages::Datagram_Type_ACQ_BODY:
			onBodyStream(datagram->mutable_data()); break;
		default:
			LOG_WARN("Received unimplemented datagram type : " + std::to_string(datagramType));
	}

	delete datagram;
}

void TrackerClient::onBodyStream(const protobuf::Any * data) {
	// Decode the data
	messages::RawBody messageBody;

	try {
		data->UnpackTo(&messageBody);
	} catch (protobuf::FatalException e) {
		LOG_ERROR("Error while deserializing a body. Ignoring...");
		LOG_DEBUG(e.message());

		return;
	}

	RawBody * rawBody = new RawBody(messageBody);

	// LOG_INFO("Received a body from the stream");

	if(onRawBody)
		onRawBody(rawBody);
}

void TrackerClient::socketDidClose(Socket *socket) {
	if(onClose) {
		onClose(this);
	}
}

} /* ::master */
} /* ::pb */
