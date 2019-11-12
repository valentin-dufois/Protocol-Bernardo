//
//  BroadcastSocket.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-11-12.
//

#include <iostream>
#include <google/protobuf/util/json_util.h>

#include "BroadcastSocket.hpp"

#include "../CommunicationEngine.hpp"
#include "../../Utils/Log.hpp"
#include "../../Utils/flags.hpp"

BroadcastSocket::BroadcastSocket():
_socket(CommunicationEngine::instance()->getContext()) { }

void BroadcastSocket::open(const int &port) {
	_broadcastEndpoint = asio::ip::udp::endpoint(asio::ip::address_v4::broadcast(), port);

	boost::system::error_code error;

	_socket.open(asio::ip::udp::v4(), error);

	if(error) {
		LOG_ERROR("Could not open a UDP Socket");
		LOG_ERROR(error.message());
		return;
	}

	// Get the interface
	asio::ip::address outboundAddress = getInterface();

	LOG_DEBUG("Broadcasting on interface " + outboundAddress.to_string());

	// Set the options
	_socket.set_option(asio::ip::multicast::outbound_interface(outboundAddress.to_v4()));
	_socket.set_option(asio::ip::udp::socket::reuse_address(true));
	_socket.set_option(asio::socket_base::broadcast(true));

	_socket.bind(asio::ip::udp::endpoint(outboundAddress, 0), error);

	if(error) {
		LOG_ERROR("Could not open a UDP Socket");
		LOG_ERROR(error.message());
		return;
	}

	// Run the context
	CommunicationEngine::instance()->runContext();

	_isBroadcasting = true;
}

void BroadcastSocket::emit(const protobuf::Message * message) {
	// Put the message in a buffer
	asio::streambuf outputBuffer;
	std::ostream os(&outputBuffer);
	message->SerializeToOstream(&os);

	emit(outputBuffer);
}


void BroadcastSocket::emitAsJSON(const protobuf::Message * message) {
	std::string outputString;
	protobuf::util::MessageToJsonString(*message, &outputString);

	asio::streambuf outputBuffer;
	std::iostream os(&outputBuffer);
	os << outputString;

	emit(outputBuffer);
}

void BroadcastSocket::emit(const asio::streambuf &ob) {
	emitMutex.lock();

	if(!_isBroadcasting) {
		emitMutex.unlock();
		return;
	}

	boost::system::error_code error;
	_socket.send_to(ob.data(), _broadcastEndpoint, boost::asio::socket_base::message_flags(), error);

	emitMutex.unlock();

	if(error) {
		LOG_ERROR("Error while broadcasting");
		LOG_ERROR(error.message());
		close();
	}
}

void BroadcastSocket::close() {
	if(!_isBroadcasting)
		return;

	emitMutex.lock();

	_isBroadcasting = false;

	_socket.close();

	emitMutex.unlock();
}

BroadcastSocket::~BroadcastSocket() {
	close();
}

asio::ip::address BroadcastSocket::getInterface() {
	// The user has specified a specific outbound interface
	if(FLAGS_broadcastInterface.size() > 0) {
		return asio::ip::make_address_v4(FLAGS_broadcastInterface);
	}

	std::vector<asio::ip::address> interfaces = CommunicationEngine::instance()->getOutboundInterfaces();

	if(interfaces.size() == 0) {
		// No IPv4 interface could be found
		LOG_WARN("Could not found an IPv4 outbound interface");

		return asio::ip::address::from_string("0.0.0.0");
	}

	if(interfaces.size() == 1) {
		return interfaces[0];
	}

	// Request user input for selecting the network interface to use
	LOG_WARN("Found " + std::to_string(interfaces.size()) + " ipv4 network interface.s");
	LOG_INFO("Please select interface to use for broadcasting on the network:");

	std::string queryInteraces = "";
	for(int i = 0; i < interfaces.size(); ++i) {
		queryInteraces += "(" + std::to_string(i) + ") " + interfaces[i].to_string() + "  ";
	}

	LOG_INFO(queryInteraces);
	std::cout << ">> ";
	std::string selectedInterface;
	std::cin >> selectedInterface;

	return interfaces[std::atoi(selectedInterface.c_str())];
}
