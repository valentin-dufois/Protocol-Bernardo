//
//  Receiver.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#include <boost/bind.hpp>

#include "Receiver.hpp"

#include "../../Utils/Log.hpp"
#include "../NetworkEngine.hpp"
#include <google/protobuf/util/json_util.h>

namespace pb {
namespace network {

void Receiver::listen() {
	if(_isListening || getStatus() != ready)
		return;

	_isListening = true;

	prepareReceive();

	Engine::instance()->runContext();
}

void Receiver::prepareReceive() {
//	 getSocket().async_receive(asio::buffer(_receptionBuffer), [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {
//		 if(error)
//			 LOG_ERROR("ERR");
//		handleReceive(error, bytes_transferred);
//	});

	getSocket().async_receive(asio::buffer(_receptionBuffer), boost::bind(&Receiver::handleReceive, this, boost::asio::placeholders::error(), boost::asio::placeholders::bytes_transferred()));
}

void Receiver::handleReceive(const boost::system::error_code &error, std::size_t bytes_transferred) {

#ifdef MACHINE_RECEIVER_TOUCH
	if(bytes_transferred < 5) {
		return close(true);
	}
#else
	// Check for any error during reception
	if(error) {
		if(error == asio::error::eof) {
			// We received an eof, the socket closed on the other side.
			// Let's close on this side too
			return close(true);
		}

		// Unknown error, ignore this
		LOG_ERROR("Error while receiving data. Closing socket");
		LOG_ERROR(error.message());
		return close(true);
	}
#endif

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

	// Check we haven't reached the buffer size
	if(bytes_transferred >= RECEPTION_BUFFER_SIZE) {
		LOG_WARN("TCP Connection reception buffer sized reach. If the message was larger than the buffer size, ignoring packet");

		delete datagram;
		return;
	}

	// Pass along the received datagram
	onReceive(datagram);

	return prepareReceive();
}

} /* ::network */
} /* ::pb */
