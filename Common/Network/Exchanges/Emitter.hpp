//
//  Emitter.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#ifndef Emitter_hpp
#define Emitter_hpp

#include <mutex>

#include <boost/asio.hpp>

#include "SocketStatus.hpp"
#include "../Messages/messages.hpp"
#include "../NetworkEngine.hpp"

namespace asio = boost::asio;

namespace pb {
namespace network {

/// The Emitter class provides methods to emit data on a socket
class Emitter {
public:

	Emitter(): _outputStream(&_outputBuffer) {}

	/// Sends the given message to the connected remote
	///
	///	If the socket is sent to send data synchronously this method
	///	will block until the end of the emission
	///	of the emission
	///
	/// @param message The message to send
	void send(const protobuf::Message * message);

	/// Convenience operator for calling the send method;
	Emitter * operator << (const protobuf::Message * message) {
		send(message);
		return this;
	}

protected:

	virtual asio::ip::tcp::socket & getSocket() = 0;

	virtual SocketStatus getStatus() = 0;

	virtual EmissionType getEmissionType() = 0;

	virtual SocketFormat getFormat() = 0;

	virtual void onError() = 0;

private:

	/// Send a message to the server synchronously.
	/// @param message The message to send
	void sendSync(const protobuf::Message * message);

	std::mutex _sendMutex;

	/// Synchronous send output stream
	std::ostream _outputStream;

	/// Synchronous send output buffer
	asio::streambuf _outputBuffer;

	/// Send a message to the server asynchronously
	void sendAsync(const protobuf::Message * message);

	/// Format the given message in the format defined by `getFormat()` and put it in the given `sdt::oStream`;
	/// @param message The message to format
	/// @param _outputStream The receiving stream
	void formatMessageToStream(const protobuf::Message * message, std::ostream & _outputStream);
};

} /* ::network */
} /* ::pb */

#endif /* Emitter_hpp */
