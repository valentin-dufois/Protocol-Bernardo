//
//  MasterServer.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-02.
//

#include "MasterServer.hpp"

#include <boost/bind.hpp>

#include "../../../Common/CommunicationEngine/Exchanges/Socket.hpp"

void MasterServer::onClient(Socket * newSocket) {
	// Stop advertising once we have one connection
	endAdvertising();

	// This is a new connection, set it up
	newSocket->onDatagram = [&, newSocket] (google::protobuf::Message * aMessage) {
		onDatagram((messages::Datagram *)aMessage, newSocket);
	};

	newSocket->listen();
}

void MasterServer::onSocketClosed(Socket * closedSocket) {
	if(socketsCount() == 0) {
		// No more connections to this server, restart the advertiser
		advertise();
	}
}

void MasterServer::onDatagram(messages::Datagram * datagram, Socket * socket) {
	LOG_DEBUG("Received a datagram");

	messages::Datagram_Type datagramType = datagram->type();

	// Make sure the datagram is really for us. Master datagram types numbers are comprised between 0-100 (Common) and 200-300 (Master)
	if(datagramType == 0 || (datagramType > 100 && datagramType < 200) || datagramType >= 300) {
		// This datagram isn't for us
		LOG_WARN("Received an unsupported datagram");
		return;
	}

	// Dispatch the datagram
	switch (datagramType) {
			// Commons
		case messages::Datagram_Type::Datagram_Type_CLOSE:
			socket->close(true); break;
		case messages::Datagram_Type::Datagram_Type_PING:
			onPing(datagram->mutable_data(), socket); break;
		case messages::Datagram_Type::Datagram_Type_PONG:
			onPong(datagram->mutable_data(), socket); break;
			// Layout
		default:
			LOG_WARN("Unimplemented datagram type : " + std::to_string(datagramType));
	}
}

