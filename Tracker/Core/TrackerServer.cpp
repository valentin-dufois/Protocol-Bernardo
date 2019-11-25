//
//  TrackerServer.cpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-27.
//

#include <boost/bind.hpp>

#include "TrackerServer.hpp"

namespace pb {
namespace tracker {

using namespace pb::network;

void TrackerServer::sendRawBodies(const std::set<pb::RawBody *, RawBodyComparator> rawBodies) {
	messages::Datagram * datagram;

	for(pb::RawBody * rawBody: rawBodies) {
		datagram = makeDatagram(messages::Datagram_Type_ACQ_BODY, (messages::RawBody)*rawBody);

		for(Socket * socket: _socketsForBodyStream) {
			socket->send(datagram);
		}

		datagram->Clear();
		delete datagram;
	}
}

void TrackerServer::socketDidOpen(Socket * newSocket) {
	Server::socketDidOpen(newSocket);
	
	// Stop advertising once we have one connection
	endAdvertising();
}

void TrackerServer::socketDidReceive(Socket * socket, messages::Datagram * datagram) {
	// LOG_DEBUG("Received a datagram");

	messages::Datagram_Type datagramType = datagram->type();

	// Dispatch the datagram
	switch (datagramType) {
			// Tracker
		case messages::Datagram_Type_ACQ_GET_BODY_STREAM:
			onBodyStreamRequest(socket);
			break;
		case messages::Datagram_Type_ACQ_END_BODY_STREAM:
			onEndBodyStreamRequest(socket);
			break;


		default:
			LOG_WARN("Received an unimplemented datagram type : " + std::to_string(datagramType));
	}

	datagram->Clear();
	delete datagram;
}

void TrackerServer::socketDidClose( Socket * closedSocket) {
	Server::socketDidClose(closedSocket);

	// Make sure the socket is removed from the body stream
	onEndBodyStreamRequest(closedSocket);

	if(socketsCount() == 0) {
		// No more connections to this server, restart the advertiser
		advertise();
	}
}


// MARK: - Datagram Handlers

void TrackerServer::onBodyStreamRequest(Socket * socket) {
	// Make sure the socket isn't already registered
	if(std::find(_socketsForBodyStream.begin(), _socketsForBodyStream.end(), socket) != _socketsForBodyStream.end()) {
		LOG_ERROR("The socket is already listening to the body stream");
		return;
	}

	LOG_INFO("Registering a new listener for the body stream");
	_socketsForBodyStream.push_back(socket);
}

void TrackerServer::onEndBodyStreamRequest(Socket * socket) {
	// Remove the socket from the rergistered ones for the body stream
	_socketsForBodyStream.erase(std::find(_socketsForBodyStream.begin(),
										  _socketsForBodyStream.end(),
										  socket));

	LOG_INFO("Removing a listener of the body stream");
}

} /* tracker */
} /* pb */
