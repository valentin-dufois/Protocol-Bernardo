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
#include "Emitter.hpp"
#include "Receiver.hpp"
#include "../Endpoint.hpp"
#include "../Server.hpp"
#include "../CommunicationEngine.hpp"

namespace asio = boost::asio;

class Socket: public Emitter, public Receiver {
public:

	Socket(): Socket(CommunicationEngine::instance()->getContext()) {}

	Socket(asio::io_context &aContext):
		_socket(aContext),
		_heartbeatTimer(aContext) {}

	/// Connects the socket to the given endpoint
	void connectTo(const Endpoint &remote);

	/// Terminates the connection, closing the socket.
	///
	/// This method may be called by the socket on itself if certain conditions are
	/// met, such as when the remote closes the socket on its side.
	/// Calls to this method triggers the callback `onClose`.
	///
	/// @param silent Trus if the other side of the socket should be told about the
	/// closing
	void close(bool silent = false) override;

	~Socket();


	// MARK: - Callbacks

	/// This method is called when the connection is opened
	std::function<void()> onConnectionOpened;

	/// Called when the socket disconnects/closes
	///
	/// Once the socket is closed, a new one should be used to re-open the connection
	/// if needed
	///
	/// Calling the destructor on the socket will not trigger this callback
	std::function<void()> onClose;

	// MARK: - Accessors

	/// Gives the underlying asio socket
	inline asio::ip::tcp::socket & getSocket() override { return _socket; }

	/// Gives the status of the socket
	inline SocketStatus getStatus() override { return _status; }

	/// Gives the remote endpoint this socket is connected to
	inline Endpoint getRemote() { return _remote; }

protected:

	void onOpenedFromRemote(const Endpoint::Type &remoteType);

	void onTimeout(const boost::system::error_code& error) override;

	void onError() override;

	friend Server;

private:

	/// The status of the socket
	std::atomic<SocketStatus> _status = SocketStatus::idle;

	/// The underlying Asio socket
	asio::ip::tcp::socket _socket;

	/// The remote endpoint this socket is connected. Irrelevant if the socket status
	/// isn't `SocketStatus::ready`
	Endpoint _remote;

	asio::deadline_timer _heartbeatTimer;

	messages::Datagram _heartbeat;

	void emitHeartbeat();

};

#endif /* Socket_hpp */
