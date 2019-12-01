//
//  TrackersServer.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-30.
//

#include "TrackersServer.hpp"

#include "../../TrackingEngine/TrackingEngine.hpp"
#include "../../../Common/Structs/RawBody.hpp"

namespace pb {
namespace master {

void TrackersServer::socketDidOpen(Socket * socket) {
	Server::socketDidOpen(socket);
}

void TrackersServer::socketDidReceive(Socket * socket, messages::Datagram * datagram) {
	Server::socketDidReceive(socket, datagram);

	messages::Datagram_Type datagramType = datagram->type();

	// Dispatch based on the datagram type
	switch (datagramType) {
			// Tracker
		case messages::Datagram_Type_RAW_BODY:
			onBodyStream(datagram->mutable_data()); break;
		default:
			LOG_WARN("Received unimplemented datagram type : " + std::to_string(datagramType));
	}

	delete datagram;
}

void TrackersServer::socketDidClose(Socket * socket) {
	Server::socketDidClose(socket);
}

void TrackersServer::onBodyStream(const protobuf::Any * data) {
	// Decode the data
	messages::RawBody messageBody;

	try {
		data->UnpackTo(&messageBody);
	} catch (protobuf::FatalException e) {
		LOG_ERROR("Error while deserializing a body. Ignoring...");
		LOG_DEBUG(e.message());

		return;
	}

	trackingEngine->onRawBody(new RawBody(messageBody));
}

} /* ::master */
} /* ::pb */
