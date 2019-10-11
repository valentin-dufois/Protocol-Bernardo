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

Server::Server(const Endpoint::Type &aType): _type(aType) {
	// Set our port
	switch (_type) {
		case Endpoint::acquisitor: _port = ACQUISITOR_SERVER_PORT; break;
		case Endpoint::broadcaster: _port = BROADCASTER_SERVER_PORT; break;
		case Endpoint::master: _port = MASTER_SERVER_PORT; break;
		case Endpoint::terminal:
			LOG_ERROR("Could not build a server with a `Terminal` type");
			throw std::runtime_error("SERVER::CONSTRUCT - INVALID_TYPE");
		default:
			LOG_ERROR("Could not build a server with an undefined type");
			throw std::runtime_error("SERVER::CONSTRUCT - INVALID_TYPE");
	}

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

void Server::sendToAll(const google::protobuf::Message * aMessage, const bool &async) {
	for(Socket * s: _connections) {
		s->send(aMessage, async);
	}
}

void Server::handleClose(Socket * closedSocket) {
	// The socket is closed, remove it from the array of connections
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
