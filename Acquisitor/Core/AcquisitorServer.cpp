//
//  AcquisitorServer.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-27.
//

#include "AcquisitorServer.hpp"

#include <boost/bind.hpp>

#include "../../Common/CommunicationEngine/Exchanges/Socket.hpp"

using messages::Datagram_Type;

void AcquisitorServer::sendRawBodise(const std::list<RawBody *> rawBodies) {
	messages::RawBodies rawBodiesMessage;

	for(RawBody * rawBody: rawBodies) {
		messages::RawBody * rawBodyMessage = rawBodiesMessage.add_rawbodies();
		rawBodyMessage->CopyFrom((messages::RawBody)*rawBody);
	}

	messages::Datagram * datagram = messages::makeDatagram(messages::Datagram_Type_ACQ_BODY, rawBodiesMessage);

	for(Socket * socket: _socketsForBodyStream) {
		socket->send(datagram, false);
	}

	datagram->Clear();
	delete datagram;
}

void AcquisitorServer::onClient(Socket * newSocket) {
	// Stop advertising once we have one connection
	endAdvertising();

	// This is a new connection, set it up
	newSocket->onDatagram = [&, newSocket] (google::protobuf::Message * aMessage) {
		onDatagram((messages::Datagram *)aMessage, newSocket);
	};

	newSocket->listen();
}

void AcquisitorServer::onSocketClosed(Socket * closedSocket) {
	// Make sure the socket is removed from the body stream
	onEndBodyStreamRequest(closedSocket);

	if(socketsCount() == 0) {
		// No more connections to this server, restart the advertiser
		advertise();
	}
}

void AcquisitorServer::onDatagram(messages::Datagram * datagram, Socket * socket) {
	// LOG_DEBUG("Received a datagram");

	messages::Datagram_Type datagramType = datagram->type();

	// Make sure the datagram is really for us. Acquisitor datagram types numbers are comprised between 0-100 (Common) and 100-200 (Acquisitor)
	if(datagramType == 0 || datagramType >= 200) {
		// This datagram isn't for us
		LOG_WARN("Received an unsupported datagram");
		return;
	}

	// Dispatch the datagram
	switch (datagramType) {
		// Commons
		case messages::Datagram_Type_CLOSE:
			socket->close(true); break;
		case messages::Datagram_Type_HEARTBEAT:
			// LOG_DEBUG("Received a heartbeat");
			break;
		case messages::Datagram_Type_PING:
			onPing(datagram->mutable_data(), socket);
			break;
		case messages::Datagram_Type_PONG:
			onPong(datagram->mutable_data(), socket);
			break;

		// Acquisitor
		case messages::Datagram_Type_ACQ_GET_BODY_STREAM:
			onBodyStreamRequest(socket);
			break;
		case messages::Datagram_Type_ACQ_END_BODY_STREAM:
			onEndBodyStreamRequest(socket);
			break;


		default:
			LOG_WARN("Unimplemented datagram type : " + std::to_string(datagramType));
	}

	datagram->Clear();
	delete datagram;
}


// MARK: - Datagram Handlers

void AcquisitorServer::onBodyStreamRequest(Socket * socket) {
	// Make sure the socket isn't already registered
	if(std::find(_socketsForBodyStream.begin(), _socketsForBodyStream.end(), socket) != _socketsForBodyStream.end()) {
		LOG_ERROR("The socket is already listening to the body stream");
		return;
	}

	LOG_INFO("Registering a new listener for the body stream");
	_socketsForBodyStream.push_back(socket);
}

void AcquisitorServer::onEndBodyStreamRequest(Socket * socket) {
	// Remove the socket from the rergistered ones for the body stream
	_socketsForBodyStream.erase(std::find(_socketsForBodyStream.begin(),
										  _socketsForBodyStream.end(),
										  socket));

	LOG_INFO("Removing a listener of the body stream");
}

