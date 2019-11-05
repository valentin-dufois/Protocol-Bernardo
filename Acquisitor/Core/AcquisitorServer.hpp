//
//  AcquisitorServer.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-27.
//

#ifndef AcquisitorServer_hpp
#define AcquisitorServer_hpp

#include "../../Common/Structs/RawBody.hpp"

#include "../../Common/Messages/messages.hpp"
#include "../../Common/CommunicationEngine/Server.hpp"
#include "../../Common/CommunicationEngine/Exchanges/Datagrams/Ping.hpp"

class Socket;

/// Handles data exchange with a connected master. The acquisitor server can support
/// multiple clients but is configured to stop advertising itself as soon as it has
/// one client.
class AcquisitorServer: Server, Ping {
public:

	AcquisitorServer(const Endpoint::Type &aType): Server(aType) {
		open();
		advertise();
	}

	/// Emits the given body to all the sockets registered on the body stream
	void sendBody(const RawBody * body);

protected:
	/// Called by the server when a new connections opens
	/// @param newSocket The new connection
	void onClient(Socket * newSocket) override;

	/// Called when a socket closes. The passed socket is already closed and cannot
	/// exchange data anymore.
	/// @param closedSocket The closed socket.
	void onSocketClosed(Socket * closedSocket) override;

private:

	/// Called by the connected sockets everytime a datagram is received
	/// @param datagram The datagram received
	/// @param socket The socket who received the datagram
	void onDatagram(messages::Datagram * datagram, Socket * socket);

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

#endif /* AcquisitorServer_hpp */
