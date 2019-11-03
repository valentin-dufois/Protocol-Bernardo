//
//  Ping.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-30.
//

#include "Ping.hpp"

#include "../Socket.hpp"
#include "../../../Messages/messages.hpp"

#include <chrono>

using timeScale = std::chrono::milliseconds;

void Ping::ping(Socket * socket) {
	long long now = std::chrono::duration_cast<timeScale>(std::chrono::system_clock::now().time_since_epoch()).count();

	messages::Ping ping;
	ping.set_time(now);

	google::protobuf::Any * data = new google::protobuf::Any();
	data->PackFrom(ping);

	messages::Datagram * datagram = new messages::Datagram();
	datagram->set_type(messages::Datagram_Type::Datagram_Type_PING);
	datagram->set_allocated_data(data);

	LOG_DEBUG("Sending a ping to " + socket->getRemote().ip);
	socket->send(datagram, true);
}

void Ping::onPing(google::protobuf::Any * data, Socket * socket) {
	// Say we received a ping
	LOG_INFO("Relaying a ping");

	// Relay the ping to its sender directly
	messages::Datagram * datagram = new messages::Datagram();
	datagram->set_type(messages::Datagram_Type::Datagram_Type_PONG);
	datagram->set_allocated_data(data);

	socket->send(datagram, true);
}

void Ping::onPong(google::protobuf::Any * data, Socket * socket) {
	long long now = std::chrono::duration_cast<timeScale>(std::chrono::system_clock::now().time_since_epoch()).count();

	messages::Ping pong;
	data->UnpackTo(&pong);

	std::string duration = std::to_string((now - pong.time()));
}
