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

#include "SocketStatus.hpp"
#include "SocketDelegate.hpp"
#include "Emitter.hpp"
#include "Receiver.hpp"
#include "Datagrams/Ping.hpp"
#include "../Endpoint.hpp"
#include "../Server.hpp"
#include "../NetworkEngine.hpp"

namespace asio = boost::asio;

namespace pb {
namespace network {

/// A Socket represents a connection over the network between two machines.
///
/// A Socket handles all logics needed to open a connection, send and receive datagrams, and close the connection.
/// Received datagrams, as well as multiple events, can be catched using a SocketDelegate subclass.
class Socket: public Ping, public Emitter, public Receiver {
public:

	// MARK: - Lifecycle

	Socket(): Socket(Engine::instance()->getContext()) {}

	Socket(asio::io_context &aContext):
		_socket(aContext) {}

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
	void close(bool silent = false) override;

	~Socket();

	SocketDelegate * delegate = nullptr;

	// MARK: - Getters & Setters

	/// Gives the underlying asio socket
	inline asio::ip::tcp::socket & getSocket() override {
		return _socket;
	}

	/// Gives the status of the socket
	inline SocketStatus getStatus() override {
		return _status;
	}

	/// Gives the `EmissionType` of the socket
	inline EmissionType getEmissionType() override {
		return _emissionType;
	}

	/// Sets the `EmissionType` of the socket
	/// @param et An emission type
	inline void setEmissionType(const EmissionType &et) {
		_emissionType = et;
	}

	/// Gives the exchange format used by the socket
	inline SocketFormat getFormat() override {
		return _format;
	}

	/// Sets the exchange format used by the socket
	/// @param aFormat An exchange format
	inline void setFormat(const SocketFormat &aFormat) {
		_format = aFormat;
	}
	/// Gives the remote endpoint this socket is connected to
	inline Endpoint getRemote() {
		return _remote;
	}

protected:

	/// Executed when the socket was created by another endpoint
	/// @param remoteType The type of the other endpoint
	void onOpenedFromRemote(const Endpoint::Type &remoteType);

	/// Executed when a fatal error occur during emission or reception
	void onError() override;

	/// Gives the delagate of the socket
	inline SocketDelegate * getDelegate() {
		return delegate;
	}

	friend class Server;

	/// The underlying Asio socket
	asio::ip::tcp::socket _socket;

	/// The status of the socket
	SocketStatus _status = SocketStatus::idle;

	/// The socket emission type
	EmissionType _emissionType = EmissionType::sync;

	/// The socket exchange format
	SocketFormat _format = SocketFormat::protobuf;

	/// The remote endpoint this socket is connected. Irrelevant if the
	/// socket status isn't `SocketStatus::ready`
	Endpoint _remote;

	/// Called everytime a datagram is received
	void onReceive(protobuf::Message * message) override;
};

} /* ::network */
} /* ::pb */

#endif /* Socket_hpp */
