//
//  Receiver.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#ifndef Receiver_hpp
#define Receiver_hpp

#define RECEPTION_BUFFER_SIZE 32768

#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "SocketStatus.hpp"
#include "../Messages/messages.hpp"

namespace asio = boost::asio;

namespace pb {
namespace network {

class Receiver {
public:

	/// Tells the connection to start listening on datagram from the remote
	void listen();

	/// Tell if the receiver is actively listening
	inline bool isListening() { return _isListening; }

protected:

	virtual asio::ip::tcp::socket & getSocket() = 0;

	virtual SocketStatus getStatus() = 0;

	virtual SocketFormat getFormat() = 0;

	virtual void close(bool silent = true) = 0;

	virtual void onError() = 0;

	/// Called everytime a datagram is received
	virtual void onReceive(protobuf::Message * datagram) = 0;

private:

	/// True if listening, false otherwise
	bool _isListening = false;

	/// Prepare the connection to receive new datagram
	void prepareReceive();

	/// Handles received datagram
	void handleReceive(const boost::system::error_code &error, std::size_t bytes_transferred);

	/// The reception buffer holding incoming informations
	boost::array<char, RECEPTION_BUFFER_SIZE> _receptionBuffer;
};

} /* ::network */
} /* ::pb */

#endif /* Receiver_hpp */
