//
//  Emitter.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#include "Emitter.hpp"

#include "../../Utils/Log.hpp"

void Emitter::send(const google::protobuf::Message * message, const bool async) {
	// Make sure the socket is ready to send data
	if(getStatus() != SocketStatus::ready) {
		LOG_WARN("Could not send data on a not-ready socket. The socket may not be opened yet or is already closed.");
		return;
	}

	if(async)
		sendAsync(message);
	else
		sendSync(message);
}

void Emitter::sendSync(const google::protobuf::Message * message) {
	// Send the message to the output buffer (through the outputStream)
	message->SerializeToOstream(&_outputStream);

	startTimer();

	// Send the datagram
	getSocket().send(_outputBuffer.data());

	endTimer();

	// Clear the buffer
	_outputBuffer.consume(_outputBuffer.size());
}

void Emitter::sendAsync(const google::protobuf::Message *message) {
	// Default output buffer is not used as output buffer must be preserved valid on async calls
	asio::streambuf * outputBuffer = new asio::streambuf();
	std::ostream outputStream(outputBuffer);

	message->SerializeToOstream(&outputStream);

	startTimer();

	// Send the datagram
	getSocket().async_write_some(outputBuffer->data(), [&, outputBuffer] (const boost::system::error_code &error, std::size_t bytes_transferred) {
		endTimer();

		// Free the buffer used
		delete outputBuffer;
	});
}
