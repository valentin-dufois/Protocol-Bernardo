//
//  Receiver.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#include "Receiver.hpp"

#include "../../Utils/Log.hpp"

void Receiver::listen() {
	if(_isListening || getStatus() != ready)
		return;

	_isListening = true;

	prepareReceive();
}

void Receiver::prepareReceive() {
	getSocket().async_receive(asio::buffer(_receptionBuffer), [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {
		onReceive(error, bytes_transferred);
	});
}

void Receiver::onReceive(const boost::system::error_code &error, std::size_t bytes_transferred) {

	// LOG_DEBUG("Received " + std::to_string(bytes_transferred) + " bytes of data");

	// Check for any error during reception
	if(error) {
		if(error == asio::error::eof) {
			// We received an eof, the socket closed on the other side.
			// Let's close on this side too
			return close();
		}

		// Unknown error, ignore this
		LOG_INFO("Error while receiving data : " + error.message());
		return prepareReceive();
	}

	messages::Datagram * datagram = new messages::Datagram;
	datagram->ParseFromArray(_receptionBuffer.data(), (int)bytes_transferred);

	// Check we haven't reached the buffer size
	if(bytes_transferred >= RECEPTION_BUFFER_SIZE) {
		LOG_WARN("TCP Connection reception buffer sized reach. If the message was larger than the buffer size, further behaviour is undefined and may produce errors");
	}

	// Pass along the received datagram
	if(onDatagram)
		onDatagram(datagram);

	return prepareReceive();
}
