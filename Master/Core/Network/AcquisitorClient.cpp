
//
//  AcquisitorClient.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-27.
//

#include "AcquisitorClient.hpp"

#include "../../../Common/Structs/RawBody.hpp"

#include "../../../Common/CommunicationEngine/CommunicationEngine.hpp"
#include "../../../Common/Messages/messages.hpp"

using messages::Datagram_Type;

AcquisitorClient::AcquisitorClient() {
	_socket.onConnectionOpened = std::bind(&AcquisitorClient::onConnectionOpened, this);

	_socket.onDatagram = [&] (google::protobuf::Message * aMessage) {
		onDatagram((messages::Datagram *)aMessage);
	};

	_socket.onClose = [&] {
		if(onClose) onClose();
	};

}

void AcquisitorClient::requestBodyStream() {
	messages::Datagram datagram;
	datagram.set_type(messages::Datagram_Type_ACQ_GET_BODY_STREAM);

	_socket.send(&datagram);
}


void AcquisitorClient::onConnectionOpened() {
	LOG_INFO("Connection opened");

	_socket.listen();

	ping(&_socket);

	if(onConnected)
		onConnected(_socket.getRemote());
}

void AcquisitorClient::onDatagram(messages::Datagram * datagram) {
	LOG_DEBUG("Received a datagram");

	messages::Datagram_Type datagramType = datagram->type();

	// Make sure the parcel is really for us. Acquisitor datagrams numbers are comprised between 0-100 (Common) and 100-200 (Acquisitor)
	if(datagramType == 0 || datagramType >= 200) {
		// This datagram isn't for us
		LOG_WARN("Received an unexpected parcel");
		return;
	}

	// Dispatch based on the datagram type
	switch (datagramType) {
		// Commons
		case messages::Datagram_Type_CLOSE:
			_socket.close(true); break;

		case messages::Datagram_Type_HEARTBEAT:
			LOG_DEBUG("Received a heartbeat"); break;

		case messages::Datagram_Type_PING:
			onPing(datagram->mutable_data(), &_socket); break;

		case messages::Datagram_Type_PONG:
			onPong(datagram->mutable_data(), &_socket); break;

		// Acquisitor
		case messages::Datagram_Type_ACQ_BODY:
			onBodyStream(datagram->mutable_data()); break;

		//
		default:
			LOG_WARN("Unimplemented datagram type : " + std::to_string(datagramType));
	}

	datagram->Clear();
	delete datagram;
}

void AcquisitorClient::onBodyStream(const protobuf::Any * data) {
	// Decode the data
	messages::RawBody messageBody;
	data->UnpackTo(&messageBody);

	RawBody * body;

	try {
		body = new RawBody(messageBody);
	} catch (protobuf::FatalException e) {
		LOG_ERROR("Error while deserializing a body. Ignoring...");
		LOG_DEBUG(e.message());

		return;
	}

	LOG_INFO("Received a body from the stream");

	if(onBody)
		onBody(body);
}
