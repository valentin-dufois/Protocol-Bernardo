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

// MARK: - Socket

void Socket::connectTo(const std::string &ip, const NetworkPort &port) {
	connectTo(Endpoint(ip, port));
}

void Socket::connectTo(const Endpoint &remote) {
	if(_status != idle && _status != closed) {
		LOG_ERROR("This socket could not be opened");
	}

	_status = SocketStatus::connecting;

	_remote = remote;

	// Open the socket
	boost::system::error_code ec;
	_socket.open(asio::ip::tcp::v4(), ec);

	Engine::instance()->runContext();

	// Check errors
	if(ec) {
		LOG_ERROR(ec.message());
		return;
	}

	
	LOG_DEBUG("Opening connection to " + _remote.uri());

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

	LOG_INFO("Connected to " + remote.uri());

	prepareReceive();

	_status = SocketStatus::ready;

	if(delegate)
		delegate->socketDidOpen(this);
}

void Socket::close(bool) {
	if(_status != ready)
		return;

	_status = closed;

	LOG_INFO("Closing connection with " + _remote.ip + ":" + std::to_string(_remote.port));

	boost::system::error_code ec;
	_socket.shutdown(asio::socket_base::shutdown_both, ec);
	_socket.close(ec);

	if(delegate)
		delegate->socketDidClose(this);
}

Socket::~Socket() {
	if(_status == closed)
		return;

	// Make sure the socket is properly closed
	_receiveMutex.lock();
	_sendMutex.lock();

	close();

	_sendMutex.unlock();
	_receiveMutex.unlock();
}


// MARK: - Exchanges

void Socket::send(const google::protobuf::Message * message) {
	// Make sure the socket is ready to send data
	if(getStatus() != SocketStatus::ready) {
		LOG_WARN("Could not send data on a not-ready socket. The socket may not be opened yet or is already closed.");
		return;
	}

	switch(getEmissionType()) {
		case EmissionType::sync:
			sendSync(message);
			break;
		case EmissionType::async:
			sendAsync(message);
			break;
	}
}


// MARK: - Internal

void Socket::onOpenedFromRemote(const Endpoint::Type &remoteType) {
	_remote = Endpoint(_socket.remote_endpoint());
	_remote.type = remoteType;

	_status = SocketStatus::ready;

	LOG_INFO("Connected the " + _remote.typeLabel() + " server to client on " + _remote.uri());

	prepareReceive();

	ping(this);

	if(delegate)
		delegate->socketDidOpen(this);
}

void Socket::onError() {
	close(true);
}

// MARK: - Emission

void Socket::sendSync(const google::protobuf::Message * message) {
	_sendMutex.lock();

	// Send the message to the output buffer (through the outputStream)
	formatMessageToStream(message, _outputStream);

	boost::system::error_code error;
	startTimer();

	// Send the datagram
	_socket.send(_outputBuffer.data(), boost::asio::socket_base::message_flags(), error);

	endTimer();

	if (error) {
		LOG_ERROR("An error occured while sending data synchronously");
		LOG_ERROR(error.message());

		_receiveMutex.lock();
		close(true);
		_receiveMutex.unlock();
	}

	// Clear the buffer
	_outputBuffer.consume(_outputBuffer.size());

	_sendMutex.unlock();
}

void Socket::sendAsync(const google::protobuf::Message * message) {
	// Default output buffer is not used as output buffer must be preserved valid on async calls
	asio::streambuf outputBuffer;
	std::ostream outputStream(&outputBuffer);

	formatMessageToStream(message, outputStream);

	_sendMutex.lock();

	// Send the datagram
	_socket.async_write_some(outputBuffer.data(), [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {

		if(error) {
			LOG_ERROR("An error occured while sending data asynchronously");
			LOG_ERROR(error.message());

			_receiveMutex.lock();
			close(true);
			_receiveMutex.unlock();
		}

		_sendMutex.unlock();
	});
}

void Socket::formatMessageToStream(const protobuf::Message *message, std::ostream &stream) {
	switch(getFormat()) {
		case SocketFormat::protobuf:
			message->SerializeToOstream(&stream);
			break;

		case SocketFormat::json:
			std::string messageString;
			protobuf::util::MessageToJsonString(*message, &messageString);
			stream << messageString;
			stream << "\n";
			break;
	}
}



// MARK: - Reception

void Socket::prepareReceive() {
	_socket.async_receive(asio::buffer(_receptionBuffer), boost::bind(&Socket::handleReceive, this, boost::asio::placeholders::error(), boost::asio::placeholders::bytes_transferred()));

	Engine::instance()->runContext();
}

void Socket::handleReceive(const boost::system::error_code &error, std::size_t bytes_transferred) {

	// Check for any error during reception
	if(error) {
		if(error == asio::error::operation_aborted || error == asio::error::eof)
			return;

		LOG_ERROR("Error while receiving data. Closing socket");
		LOG_ERROR(error.message());

		_sendMutex.lock();
		close(true);
		_sendMutex.unlock();
		return;
	}

	_receiveMutex.lock();

	// Check we haven't reached the buffer size
	if(bytes_transferred >= RECEPTION_BUFFER_SIZE) {
		LOG_WARN("TCP Connection reception buffer sized reach. If the message was larger than the buffer size, ignoring packet");

		_receiveMutex.unlock();
		return;
	}

	// Decode the message using the proper format
	messages::Datagram * datagram = new messages::Datagram;

	switch(getFormat()) {
		case SocketFormat::protobuf:
			datagram->ParseFromArray(_receptionBuffer.data(), (int)bytes_transferred);
			break;
		case SocketFormat::json:
			protobuf::util::JsonStringToMessage(std::string(_receptionBuffer.begin(), _receptionBuffer.end()), datagram);
			break;
	}

	// Pass along the received datagram
	onReceive(datagram);
	
	_receiveMutex.unlock();

	return prepareReceive();
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



} /* ::network */
} /* ::pb */
