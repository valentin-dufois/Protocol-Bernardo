//
//  BroadcastSocket.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-11-12.
//

#ifndef BroadcastSocket_hpp
#define BroadcastSocket_hpp

#include <mutex>
#include <boost/asio.hpp>
#include "../../Messages/messages.hpp"

namespace asio = boost::asio;

class BroadcastSocket {
public:

	BroadcastSocket();

	void open(const int &port);

	void emit(const protobuf::Message * message);

	void emitAsJSON(const protobuf::Message * message);

	void emit(const asio::streambuf &ob);

	void close();

	~BroadcastSocket();

private:

	std::atomic<bool> _isBroadcasting = false;

	asio::ip::udp::socket _socket;

	asio::ip::address getInterface();

	asio::ip::udp::endpoint _broadcastEndpoint;

	std::mutex emitMutex;
};

#endif /* BroadcastSocket_hpp */
