//
//  Socket.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#include "Socket.hpp"

#include "../../Utils/Log.hpp"

void Socket::connectTo(const Endpoint &remote) {
	if(_status != idle) {
		LOG_ERROR("This socket could not be opened");
	}

	_status = SocketStatus::connecting;

	_remote = remote;

	// Open the socket
	boost::system::error_code ec;

	_socket.open(asio::ip::tcp::v4(), ec);

	// Check errors
	if(ec) {
		LOG_ERROR(ec.message());
		return;
	}

	
	LOG_DEBUG("Opening connection to " + _remote.ip);

	// Connect synchronously
	_socket.connect(_remote, ec);

	// Check errors
	if(ec) {
		LOG_ERROR(ec.message());
		return;
	}

	LOG_INFO("Connected to " + _remote.typeLabel() + " " + remote.name + " (" + remote.ip + ")");

	_status = SocketStatus::ready;

	if(onConnectionOpened)
		onConnectionOpened();
}

void Socket::
onOpenedFromRemote(const Endpoint::Type &remoteType) {
	_remote = Endpoint(_socket.remote_endpoint());
	_remote.type = remoteType;

	_status = SocketStatus::ready;

	LOG_INFO("Connected the " + _remote.typeLabel() + " server to client on " + _remote.ip);

	if(onConnectionOpened)
		onConnectionOpened();
}

void Socket::close(bool silent) {
	if(_status != ready)
		return;

	LOG_INFO("Closing connection with " + _remote.ip + ":" + std::to_string(_remote.getPort()));

	if(!silent)
	{
		// Tell the other side of the connection that we are closing
		messages::Datagram datagram;
		datagram.set_type(messages::Datagram_Type::Datagram_Type_CLOSE);
		// No data in a close message

		// Send the close message
		send(&datagram, true, false);

	}

	_status = closed;

	boost::system::error_code ec;
	_socket.shutdown(asio::socket_base::shutdown_both, ec);
	_socket.close();

	if(onClose)
		onClose();
}

void Socket::onTimeout(const boost::system::error_code& error) {
	LOG_WARN("Remote unreachable, closing silently now.");
	close(true);
}

void Socket::onError() {
	close(true);
}

Socket::~Socket() {
	// Make sure the socket is properly closed
	close();
}
