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
#include "TimeoutHandling.hpp"
#include "../../Messages/messages.hpp"

namespace asio = boost::asio;

class Receiver: protected TimeoutHandling {
public:

	/// Tells the connection to start listening on datagram from the remote
	void listen();

	/// Called everytime a message is received
	std::function<void(google::protobuf::Message *)> onDatagram;

protected:

	virtual asio::ip::tcp::socket & getSocket() = 0;

	virtual SocketStatus getStatus() = 0;

	virtual void close(bool silent = true) = 0;
	virtual void onError() = 0;

	/// Tell if the receiver is actively listening
	inline bool isListening() { return _isListening; }

private:

	/// True if listening, false otherwise
	bool _isListening = false;

	/// Prepare the connection to receive new datagram
	void prepareReceive();

	/// Handles received datagram
	void onReceive(const boost::system::error_code &error, std::size_t bytes_transferred);

	/// The reception buffer holding incoming informations
	boost::array<char, RECEPTION_BUFFER_SIZE> _receptionBuffer;
};

#endif /* Receiver_hpp */
