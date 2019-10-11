//
//  Emitter.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#ifndef Emitter_hpp
#define Emitter_hpp

#include <boost/asio.hpp>

#include "SocketStatus.hpp"
#include "../../Messages/messages.hpp"
#include "../CommunicationEngine.hpp"
#include "TimeoutHandling.hpp"

namespace asio = boost::asio;

/// The Emitter class provides methods to emit data on a socket
class Emitter: protected TimeoutHandling {
public:

	Emitter():
	_outputStream(&_outputBuffer) {}

	/// Sends the given message to the connected remote
	///
	///	If the emission is made synchronously, this method will block until the end
	///	of the emission
	///
	/// @param message The message to send
	/// @param async Specify if the emission should be made asynchronously or not
	void send(const google::protobuf::Message * message, const bool async = true);

protected:

	virtual asio::ip::tcp::socket & getSocket() = 0;

	virtual SocketStatus getStatus() = 0;

private:

	/// Send a message to the server synchronously.
	/// @param message The message to send
	void sendSync(const google::protobuf::Message * message);

	/// Synchronous send output stream
	std::ostream _outputStream;

	/// Synchronous send output buffer
	asio::streambuf _outputBuffer;

	/// Send a message to the server asynchronously
	void sendAsync(const google::protobuf::Message * message);
};

#endif /* Emitter_hpp */
