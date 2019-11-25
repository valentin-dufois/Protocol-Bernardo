//
//  TrackerServer.hpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-27.
//

#ifndef TrackerServer_hpp
#define TrackerServer_hpp

#include <list>

#include "../../Common/Structs/RawBody.hpp"
#include "../../Common/Network.hpp"

namespace pb {
namespace tracker {

using namespace pb::network;

/// Handles data exchange with a connected master. The tracker server
/// can support multiple clients but is configured to stop advertising
/// itself as soon as it has one client.
class TrackerServer: Server, Ping {
public:

	TrackerServer(const Endpoint::Type &aType): Server(aType) {
		open();
		advertise();
	}

	/// Emits the given body to all the sockets registered on the body stream
	void sendRawBodies(const std::set<pb::RawBody *, pb::RawBodyComparator> rawBodies);

protected:
	/// Called by the server when a new connections opens
	/// @param newSocket The new connection
	virtual void socketDidOpen(Socket * newSocket) override;

	/// Called by the connected sockets everytime a datagram is received
	/// @param datagram The datagram received
	/// @param socket The socket who received the datagram
	virtual void socketDidReceive(Socket * socket, messages::Datagram * datagram) override;

	/// Called when a socket closes. The passed socket is already closed and cannot
	/// exchange data anymore.
	/// @param closedSocket The closed socket.
	virtual void socketDidClose(Socket * closedSocket) override;

private:

	// MARK: - Datagram Handlers

	/// Called by the datagram handler when a client asks for a handle on the body
	/// stream
	/// @param socket The socket who received the datagram
	void onBodyStreamRequest(Socket * socket);

	/// Called by the datagram handler when a client asks to stops receiving bodies
	/// @param socket The socket who received the message
	void onEndBodyStreamRequest(Socket * socket);

	/// List of all the subscribed socket to the body stream
	std::vector<Socket *> _socketsForBodyStream;

};

} /* tracker */
} /* pb */

#endif /* TrackerServer_hpp */
