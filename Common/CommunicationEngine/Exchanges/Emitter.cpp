//
//  Emitter.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#include "Emitter.hpp"

#include "../../Utils/Log.hpp"

#include <google/protobuf/util/json_util.h>

void Emitter::
send(google::protobuf::Message * message, const bool deleteAfterUse, const bool async) {

	_sendMutex.lock();

	// Make sure the socket is ready to send data
	if(getStatus() != SocketStatus::ready) {
		_sendMutex.unlock();
		LOG_WARN("Could not send data on a not-ready socket. The socket may not be opened yet or is already closed.");
		return;
	}

	if(async)
		sendAsync(message, deleteAfterUse);
	else
		sendSync(message, deleteAfterUse);

	_sendMutex.unlock();
}

void Emitter::sendSync(google::protobuf::Message * message, const bool deleteAfterUse) {
	// Send the message to the output buffer (through the outputStream)
	message->SerializeToOstream(&_outputStream);

	startTimer();

	boost::system::error_code error;

	// Send the datagram
	getSocket().send(_outputBuffer.data(), boost::asio::socket_base::message_flags(), error);

	if (error) {
		LOG_ERROR("An error occured while sending data synchronously");
		LOG_ERROR(error.message());
		onError();
	}

	endTimer();

	// Clear the buffer
	_outputBuffer.consume(_outputBuffer.size());

	if(deleteAfterUse) {
		delete message;
	}
}

void Emitter::sendAsync(google::protobuf::Message * message, const bool deleteAfterUse) {
	// Default output buffer is not used as output buffer must be preserved valid on async calls
	asio::streambuf outputBuffer;
	std::ostream outputStream(&outputBuffer);

	message->SerializeToOstream(&outputStream);

	if(deleteAfterUse) {
		delete message;
	}

	startTimer();

	// Send the datagram
	getSocket().async_write_some(outputBuffer.data(), [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {
		endTimer();

		if(error) {
			LOG_ERROR("An error occured while sending data asynchronously");
			LOG_ERROR(error.message());
			onError();
		}
	});
}

void Emitter::sendAsJson(protobuf::Message * message) {
	std::string outputString;
	protobuf::util::MessageToJsonString(*message, &outputString);

	asio::streambuf outputBuffer;
	std::iostream os(&outputBuffer);
	os << outputString;

	boost::system::error_code error;

	// Send the datagram
	getSocket().send(outputBuffer.data(), boost::asio::socket_base::message_flags(), error);

	CommunicationEngine::instance()->runContext();

	if (error) {
		LOG_ERROR("An error occured while sending data synchronously");
		LOG_ERROR(error.message());
		onError();
	}

	// Clear the buffer
	_outputBuffer.consume(_outputBuffer.size());

}
