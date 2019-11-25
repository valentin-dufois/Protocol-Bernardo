//
//  Emitter.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#include "Emitter.hpp"

#include "../../Utils/Log.hpp"
#include <google/protobuf/util/json_util.h>

namespace pb {
namespace network {

void Emitter::
send(const google::protobuf::Message * message) {

	_sendMutex.lock();
	
	// Make sure the socket is ready to send data
	if(getStatus() != SocketStatus::ready) {
		_sendMutex.unlock();
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

	_sendMutex.unlock();
}

void Emitter::sendSync(const google::protobuf::Message * message) {
	// Send the message to the output buffer (through the outputStream)
	formatMessageToStream(message, _outputStream);

	boost::system::error_code error;

	// Send the datagram
	getSocket().send(_outputBuffer.data(), boost::asio::socket_base::message_flags(), error);

	if (error) {
		LOG_ERROR("An error occured while sending data synchronously");
		LOG_ERROR(error.message());
		onError();
	}

	// Clear the buffer
	_outputBuffer.consume(_outputBuffer.size());
}

void Emitter::sendAsync(const google::protobuf::Message * message) {
	// Default output buffer is not used as output buffer must be preserved valid on async calls
	asio::streambuf outputBuffer;
	std::ostream outputStream(&outputBuffer);

	formatMessageToStream(message, outputStream);

	// Send the datagram
	getSocket().async_write_some(outputBuffer.data(), [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {

		if(error) {
			LOG_ERROR("An error occured while sending data asynchronously");
			LOG_ERROR(error.message());
			onError();
		}
	});
}

void Emitter::formatMessageToStream(const protobuf::Message *message, std::ostream &stream) {
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

} /* ::network */
} /* ::pb */
