//
//  Server.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-25.
//

#include <boost/bind.hpp>

#include "Server.hpp"

#include "NetworkEngine.hpp"
#include "../Utils/Log.hpp"
#include "NetworkParameters.h"
#include "Endpoint.hpp"


namespace pb {
namespace network {

Server::Server(const NetworkPort &port, const NetworkPort &discoveryPort, const Endpoint::Type &aType):
_type(aType),
_port(port),
_advertiser(discoveryPort) {
	// Build the acceptor
	_acceptor = new asio::ip::tcp::acceptor(Engine::instance()->getContext(), asio::ip::tcp::endpoint(asio::ip::tcp::v4(), _port));
}

void Server::open() {
	if(_isRunning)
		return;

	// Run the context
	Engine::instance()->runContext();

	_isRunning = true;

	// Be ready to accept new connections
	prepareAccept();
}

void Server::sendToAll(protobuf::Message * aMessage) {
	for(Socket * s: _connections) {
		s->send(aMessage);
	}
}

void Server::socketDidOpen(Socket * socket) { }

void Server::socketDidClose(Socket * socket) {
	// The socket is closed, remove it from the array of connections
	_connections.erase(std::find(_connections.begin(), _connections.end(), socket));

	delete socket;
}

void Server::prepareAccept() {
	Socket * newConnection = new Socket();
	newConnection->delegate = this;

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

	prepareAccept();
}


Server::~Server() {
	// Perform stopping actions...
	_isRunning = false;

	_acceptor->cancel();
	_acceptor->close();
	delete _acceptor;

	for(Socket * socket: _connections) {
		socket->close();

		if(socket != nullptr)
			delete socket;
	}

	_connections.clear();

	// Free used memory
	delete _acceptor;
}

} /* ::network */
} /* ::pb */
