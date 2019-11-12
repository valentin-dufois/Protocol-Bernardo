//
//  Server.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-25.
//

#include <boost/bind.hpp>

#include "Server.hpp"

#include "CommunicationEngine.hpp"
#include "../Utils/Log.hpp"
#include "NetworkParameters.h"
#include "Exchanges/Socket.hpp"
#include "Endpoint.hpp"

Server::Server(const Endpoint::Type &aType):
_type(aType),
_port(Endpoint(_type).getPort()),
_advertiser(aType) {
	// Build the acceptor
	_acceptor = new asio::ip::tcp::acceptor(CommunicationEngine::instance()->getContext(), asio::ip::tcp::endpoint(asio::ip::tcp::v4(), _port));
}

void Server::open() {
	if(_isRunning)
		return;

	// Run the context
	CommunicationEngine::instance()->runContext();

	_isRunning = true;

	// Be ready to accept new connections
	prepareAccept();
}

void Server::sendToAll(google::protobuf::Message * aMessage, const bool &deleteAfterUse, const bool &async) {
	for(Socket * s: _connections) {
		s->send(aMessage, false, async);
	}

	if(deleteAfterUse) {
		delete aMessage;
	}
}

void Server::sendToAllAsJSON(google::protobuf::Message * aMessage) {
	for(Socket * s: _connections) {
		s->sendAsJson(aMessage);
	}
}

void Server::handleClose(Socket * closedSocket) {
	// The socket is closed, remove it from the arra1y of connections
	_connections.erase(std::find(_connections.begin(), _connections.end(), closedSocket));

	onSocketClosed(closedSocket);
}

void Server::prepareAccept() {
	Socket * newConnection = new Socket(CommunicationEngine::instance()->getContext());

	_acceptor->async_accept(newConnection->getSocket(), boost::bind(&Server::handleAccept, this, newConnection, boost::asio::placeholders::error));
}

void Server::handleAccept(Socket * newConnection, const boost::system::error_code &error) {
	// Was there an error during connection ?
	if(error) {
		LOG_WARN("An error occured while accepting a connection");
		LOG_WARN(error.message());

		// Prepare the server for any new connection
		prepareAccept();
		return;
	}

	// Store the new connection
	_connections.push_back(newConnection);

	newConnection->onOpenedFromRemote(_type);
	newConnection->onClose = std::bind(&Server::handleClose, this, newConnection);

	prepareAccept();

	onClient(newConnection);
}


Server::~Server() {
	// Perform stopping actions...


	// Free used memory
	delete _acceptor;
}
