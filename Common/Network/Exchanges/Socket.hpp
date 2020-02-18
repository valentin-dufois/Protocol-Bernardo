
//
//  Socket.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#ifndef Socket_hpp
#define Socket_hpp

#include <atomic>
#include <type_traits>

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>

#include <google/protobuf/util/json_util.h>

#include "BaseSocket.hpp"
#include "Datagrams/Ping.hpp"
#include "../Server.hpp"
#include "../NetworkEngine.hpp"

#define RECEPTION_BUFFER_SIZE 128000

namespace asio = boost::asio;

namespace pb {
namespace network {

/// A Socket represents a connection over the network between two machines.
///
/// A Socket handles all logics needed to open a connection, send and receive datagrams, and close the connection.
/// Received datagrams, as well as multiple events, can be catched using a SocketDelegate subclass.
template<class MessageFormat>
class Socket: public BaseSocket, public Ping {
public:

	// MARK: - Lifecycle

	Socket(): BaseSocket() {
			static_assert(std::is_base_of<protobuf::Message, MessageFormat>::value, "The socket format is not derived from a protobuf messsage");
		}

	// MARK: - Exchanges

	/// Convenience operator for calling the send method;
	Socket<MessageFormat> * operator << (const protobuf::Message * message) {
		send(message);
		return this;
	}

	// MARK: - Getters & Setters

	// MARK: - Internal

protected:

	inline bool canPing() override {
		return std::is_same<messages::Datagram, MessageFormat>::value;
	}

	inline void ping(BaseSocket * socket) override {
		Ping::ping(socket);
	}

	// MARK: - Reception

	inline virtual protobuf::Message * decodeMessageFromBuffer(boost::array<char, RECEPTION_BUFFER_SIZE> & buffer, const std::size_t &bytes_transferred) override {
		// Decode the message using the proper format
		MessageFormat * message = new MessageFormat();

		message->ParseFromArray(buffer.data(), (int)bytes_transferred);

		return message;
	}

	inline virtual protobuf::Message * decodeMessageFromBuffer(boost::asio::streambuf * buffer, const std::size_t &bytes_transferred) override {
		MessageFormat * message = new MessageFormat();

		boost::asio::streambuf::const_buffers_type bufs = buffer->data();
		std::string messageText = std::string(boost::asio::buffers_begin(bufs),
											  boost::asio::buffers_begin(bufs) + bytes_transferred);

		protobuf::util::JsonStringToMessage(messageText, message);

		// Clear buffer
		buffer->consume(bytes_transferred);
		return message;
	}

	/// Called everytime a valid datagram is received
	inline virtual void onReceive(protobuf::Message * message) override {

		if(getFormat() == json) {
			if(delegate)
				return delegate->socketDidReceive(this, message);

			delete message;
			return;
		}

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
				close();
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
};

} /* ::network */
} /* ::pb */

#endif /* Socket_hpp */
