//
//  Socket.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#include "Socket.hpp"

#include "../../Utils/Log.hpp"

namespace pb {
namespace network {

void Socket::connectTo(const Endpoint &remote) {
	if(_status != idle && _status != closed) {
		LOG_ERROR("This socket could not be opened");
	}

	_status = SocketStatus::connecting;

	_remote = remote;

	Engine::instance()->runContext();

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
		_status = SocketStatus::idle;
		LOG_ERROR(ec.message());
		_socket.shutdown(asio::socket_base::shutdown_both, ec);
		_socket.close(ec);
		return;
	}

	LOG_INFO("Connected to " + _remote.typeLabel() + " " + remote.name + " (" + remote.ip + ")");

	_status = SocketStatus::ready;

	if(delegate)
		delegate->socketDidOpen(this);
}

void Socket::
onOpenedFromRemote(const Endpoint::Type &remoteType) {
	_remote = Endpoint(_socket.remote_endpoint());
	_remote.type = remoteType;

	_status = SocketStatus::ready;

	LOG_INFO("Connected the " + _remote.typeLabel() + " server to client on " + _remote.ip);

	ping(this);

	if(delegate)
		delegate->socketDidOpen(this);
}

void Socket::close(bool silent) {
	if(_status != ready)
		return;

	LOG_INFO("Closing connection with " + _remote.ip + ":" + std::to_string(_remote.port));

	if(!silent)
	{
		// Tell the other side of the connection that we are closing
		messages::Datagram * datagram = makeDatagram(messages::Datagram_Type::Datagram_Type_CLOSE);

		// Send the close message
		send(datagram);

		delete datagram;
	}

	_status = closed;

	boost::system::error_code ec;
	_socket.shutdown(asio::socket_base::shutdown_both, ec);
	_socket.close(ec);

	if(delegate)
		delegate->socketDidClose(this);
}

void Socket::onError() {
	close(true);
}

void Socket::onReceive(protobuf::Message * message) {
	messages::Datagram * datagram = (messages::Datagram *)message;

	messages::Datagram_Type datagramType = datagram->type();

	// Make sure the parcel is really for us. Tracker datagrams numbers are comprised between 0-100 (Common) and 100-200 (Tracker)
	if(datagramType < 10 || datagramType >= 20) {
		// This datagram isn't for us
		if(delegate)
			return delegate->socketDidReceive(this, datagram);

		delete datagram;
		return;
	}

	switch(datagramType) {
		case messages::Datagram_Type_CLOSE:
			close(true);
			break;
		case messages::Datagram_Type_PING:
			onPing(datagram->mutable_data(), this);
			break;
		case messages::Datagram_Type_PONG:
			onPong(datagram->mutable_data(), this);
			break;
		default:
			LOG_WARN("Received unrecognized Socket command " + std::to_string(datagramType));
	}

	delete datagram;
}

Socket::~Socket() {
	// Make sure the socket is properly closed
	close();
}

} /* ::network */
} /* ::pb */
