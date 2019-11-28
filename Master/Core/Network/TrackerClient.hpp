//
//  TrackerClient.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-27.
//

#ifndef TrackerClient_hpp
#define TrackerClient_hpp

#include "../../../Common/Network.hpp"

using namespace pb::network;

namespace pb {

class RawBody;

namespace master {

class TrackerClient: public SocketDelegate {
public:
	TrackerClient();

	/// Connects to the specified endpoint
	/// @param server The server to which to connect
	inline void connectTo(const Endpoint server) { _socket.connectTo(server); }

	std::function<void(const Endpoint &)> onConnected;

	/// Called everytime a body is received. The body memory has to be freed by you.
	std::function<void(RawBody *)> onRawBody;

	/// Called when the connection has closed.
	std::function<void(TrackerClient *)> onClose;

	inline Endpoint getRemote() { return _socket.getRemote(); }

	// MARK: - Socket Delegate

	void socketDidOpen(Socket *) override;

	void socketDidReceive(Socket * socket, messages::Datagram * datagram) override;

	void socketDidClose(Socket * socket) override;

	~TrackerClient();

protected:

	/// Gives a pointer to the underlying socket. Used by upperclass.
	inline Socket * getSocket() { return &_socket; }

private:
	/// The actual socket
	Socket _socket;

	// MARK: - Datagrams callbacks

	/// Called everytime a body from the body stream is received
	void onBodyStream(const protobuf::Any * data);
};

} /* ::master */
} /* ::pb */

#endif /* TrackerClient_hpp */
