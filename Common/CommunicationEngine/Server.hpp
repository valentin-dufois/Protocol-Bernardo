//
//  Server.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-25.
//

#ifndef Server_hpp
#define Server_hpp

#include <vector>
#include <boost/asio.hpp>
#include <thread>

#include "Endpoint.hpp"
#include "Discovery/Advertiser.hpp"
#include "../Messages/messages.hpp"

class Socket;

namespace asio = boost::asio;

/// A Server allows for building services and making them accessible to others on the
/// network. Conceptually, a Server should only handle a unique Service. Multiple
/// Server should be able to run concurrently on different ports (not tested).
///
/// The server class handles all the connection logic for you, exposing only the
/// necessary handles to build your services. The server class is abstract and made
/// to be subclassed. The `onClient(Socket *)` must be implemented by your own
/// server class. it will be called everytime a new client connects to the server.
///
/// Data exchange logic with clients happens at the connection level and not at the
/// server level.
///
/// The Server class can advertise itself on the network using a built in Advertiser.
class Server {
public:

	// MARK: - Lifecycle

	/// Creates the server for the specified type.
	/// @param aType The type of service this server represent
	Server(const Endpoint::Type &aType);

	/// Opens the server, making it listen to connections from the network
	void open();

	/// Sends the given 
	/// @param aMessage <#aMessage description#>
	void sendToAll(google::protobuf::Message * aMessage, const bool &deleteAfterUser = true, const bool &async = true);

	/// Start the advertiser, exposing explicitely the server on the network
	inline void advertise() { _advertiser.startAdvertising(); }

	/// Stops the advertiser
	inline void endAdvertising() { _advertiser.stopAdvertising(); }


protected:

	/// Called everytime a new client is connects to the server
	/// @param newConnection The newly opened connection
	virtual void onClient(Socket * newConnection) = 0;

	/// Called everytime a conncetion is lost. The given connection
	/// will be free-ed once this callback is completed
	/// @param closedConnection The closed connection
	virtual void onSocketClosed(Socket * closedConnection) {}

public:

	~Server();

	// MARK: - Properties

	/// Tell if the server is running
	/// @return True if running, false otherwise
	inline bool isRunning() { return _isRunning; }

protected:

	// The type of the server
	const Endpoint::Type _type;

	// The port of the server
	int _port;

	inline unsigned long socketsCount() { return _connections.size(); }

private:

	/// True if the server is opened and running, false otherwise
	bool _isRunning = false;

	/// The acceptor used to accept incoming connections
	asio::ip::tcp::acceptor * _acceptor = nullptr;

	/// Ready the server to accept a new connection
	void prepareAccept();

	/// Handls connection acception logic, and dispatch the new connection
	void handleAccept(Socket * newConnection, const boost::system::error_code &error);

	void handleClose(Socket * closedSocket);

	/// Holds a reference to all the connection to this server
	std::vector<Socket *> _connections;

	/// The underlying advertiser used to adveretise this server on the network
	Advertiser _advertiser;
};

#endif /* Server_hpp */
