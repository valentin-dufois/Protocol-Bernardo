//
//  AcquisitorClient.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-27.
//

#ifndef AcquisitorClient_hpp
#define AcquisitorClient_hpp

#include "../../../Common/CommunicationEngine/Exchanges/Socket.hpp"
#include "../../../Common/CommunicationEngine/Exchanges/Datagrams/Ping.hpp"


class RawBody;

class AcquisitorClient: Ping {
public:
	AcquisitorClient();

	/// Connects to the specified endpoint
	/// @param server The server to which to connect
	inline void connectTo(const Endpoint server) { _socket.connectTo(server); }

	std::function<void(const Endpoint &)> onConnected;

	/// Called everytime a body is received. The body memory has to be freed by you.
	std::function<void(RawBody *)> onRawBody;

	/// Called when the connection has closed.
	std::function<void()> onClose;

	// MARK: - Datagrams

	/// Asks for the body stream from the acquisitor server
	void requestBodyStream();

	~AcquisitorClient();

protected:

	/// Gives a pointer to the underlying socket. Used by upperclass.
	inline Socket * getSocket() { return &_socket; }

private:
	Socket _socket;

	/// Callbacked by the socket when the connection opens
	void onConnectionOpened();

	/// Callbacked by the socket everytime a datagram is received. Handles dispatch
	/// of datagram based on their types
	void onDatagram(messages::Datagram * datagram);

	// MARK: - Datagrams callbacks

	/// Called everytime a body from the body stream is received
	void onBodyStream(const protobuf::Any * data);
};

#endif /* AcquisitorClient_hpp */
