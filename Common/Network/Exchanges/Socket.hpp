//
//  Socket.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#ifndef Socket_hpp
#define Socket_hpp

#include <atomic>

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>

#include <google/protobuf/util/json_util.h>

#include "SocketStatus.hpp"
#include "SocketDelegate.hpp"
#include "Datagrams/Ping.hpp"
#include "../Endpoint.hpp"
#include "../Server.hpp"
#include "../NetworkEngine.hpp"

#define RECEPTION_BUFFER_SIZE 32768

namespace asio = boost::asio;

namespace pb {
namespace network {

/// A Socket represents a connection over the network between two machines.
///
/// A Socket handles all logics needed to open a connection, send and receive datagrams, and close the connection.
/// Received datagrams, as well as multiple events, can be catched using a SocketDelegate subclass.
class Socket: public Ping {
public:

	SocketDelegate * delegate = nullptr;

	// MARK: - Lifecycle

	Socket():
		_socket(Engine::instance()->getContext()),
		_outputStream(&_outputBuffer),
		_timer(Engine::instance()->getContext()) {}

	/// Connects the socket to the given ip and port
	void connectTo(const std::string &ip, const NetworkPort &port);

	/// Connects the socket to the given endpoint
	void connectTo(const Endpoint &remote);

	/// Terminates the connection, closing the socket.
	///
	/// This method may be called by the socket on itself if certain conditions are
	/// met, such as when the remote closes the socket on its side.
	/// Calls to this method triggers the callback `onClose`.
	///
	/// @param silent False if the other side of the socket should be told about the
	/// closing
	void close(bool silent = false);

	~Socket();


	// MARK: - Exchanges

	/// Sends the given message to the connected remote
	///
	///	If the socket is sent to send data synchronously this method
	///	will block until the end of the emission
	///	of the emission
	///
	/// @param message The message to send
	void send(const protobuf::Message * message);

	/// Convenience operator for calling the send method;
	Socket * operator << (const protobuf::Message * message) {
		send(message);
		return this;
	}

	// MARK: - Getters & Setters

	/// Gives the underlying asio socket
	inline asio::ip::tcp::socket & getSocket() { return _socket; }

	/// Gives the status of the socket
	inline SocketStatus getStatus() const { return _status; }

	/// Gives the `EmissionType` of the socket
	inline EmissionType getEmissionType() const { return _emissionType; }

	/// Sets the `EmissionType` of the socket
	/// @param et An emission type
	inline void setEmissionType(const EmissionType &et) { _emissionType = et; }

	/// Gives the exchange format used by the socket
	inline SocketFormat getFormat() const { return _format; }

	/// Sets the exchange format used by the socket
	/// @param aFormat An exchange format
	inline void setFormat(const SocketFormat &aFormat) {
		_format = aFormat;
	}

	/// Gives the remote endpoint this socket is connected to
	inline Endpoint getRemote() const { return _remote; }

	// MARK: - Internal

protected:

	// We want the `Server`s, and only the Servers, to be able to call `onOpenedFromRemote()`
	friend class Server;

	/// Executed when the socket was created by another endpoint
	/// @param remoteType The type of the other endpoint
	void onOpenedFromRemote(const Endpoint::Type &remoteType);

private:

	/// Executed when a fatal error occur during emission or reception
	void onError();

	/// The underlying Asio socket
	asio::ip::tcp::socket _socket;

	/// The status of the socket
	SocketStatus _status = SocketStatus::idle;

	/// The socket emission type
	EmissionType _emissionType = EmissionType::sync;

	/// The socket exchange format
	SocketFormat _format = SocketFormat::protobuf;

	/// The remote endpoint this socket is connected to. Irrelevant if the
	/// socket status isn't `SocketStatus::ready`
	Endpoint _remote;


	// MARK: - Emission

	asio::deadline_timer _timer;

	/// Mutex protecting from send errors
	std::mutex _sendMutex;

	/// Mutex protecting from receive errors
	std::mutex _receiveMutex;

	/// Synchronous send output stream
	std::ostream _outputStream;

	/// Synchronous send output buffer
	asio::streambuf _outputBuffer;

	/// Send a message to the server synchronously.
	/// @param message The message to send
	void sendSync(const protobuf::Message * message);

	/// Send a message to the server asynchronously
	void sendAsync(const protobuf::Message * message);

	/// Format the given message in the format defined by `getFormat()` and put it in the given `std::ostream`;
	/// @param message The message to format
	/// @param _outputStream The receiving stream
	void formatMessageToStream(const protobuf::Message * message, std::ostream & _outputStream);

	// MARK: Timing

	inline void startTimer() {
		_timer.expires_from_now(boost::posix_time::seconds(2));
		_timer.async_wait([&] (const boost::system::error_code &error) {
			// Operation aborted is send if the timer is cancelled, meaning no timeout1
			if(error != boost::asio::error::operation_aborted) {
				LOG_ERROR("Socket send timeout");
				close(true);
			}
		});
	}

	inline void endTimer() {
		_timer.cancel();
	}


	// MARK: - Reception

	/// The reception buffer holding incoming informations
	boost::array<char, RECEPTION_BUFFER_SIZE> _receptionBuffer;

	/// Prepare the connection to receive new datagram
	void prepareReceive();

	/// Handles received data from the network
	void handleReceive(const boost::system::error_code &error, std::size_t bytes_transferred);

	/// Called everytime a valid datagram is received
	void onReceive(protobuf::Message * message);
};

} /* ::network */
} /* ::pb */

#endif /* Socket_hpp */
