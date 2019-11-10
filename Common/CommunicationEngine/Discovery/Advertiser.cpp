//
//  Advertiser.cpp
//  CommunicationEngine
//
//  Created by Valentin Dufois on 2019-09-09.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include <boost/bind.hpp>
#include <iostream>
#include <string>

#include "Advertiser.hpp"

#include "../CommunicationEngine.hpp"
#include "../../Messages/messages.hpp"

Advertiser::Advertiser(const Endpoint::Type &endpointType):
_broadcastEndpoint(asio::ip::udp::endpoint(asio::ip::address_v4::broadcast(),
										   Endpoint(endpointType).getDiscoveryPort())) {
	Endpoint thisMachine = CommunicationEngine::thisMachine();

	// Prepare the message
	messages::Endpoint * message = thisMachine;

	// Build and store the message buffer
	std::ostream os(&_outputBuffer);
	message->SerializeToOstream(&os);
}

void Advertiser::startAdvertising() {
	if(_isRunning)
		return;

	// Open the network connection (Broadcast)
	_socket = new asio::ip::udp::socket(CommunicationEngine::instance()->getContext());
	_socket->open(asio::ip::udp::v4());

	asio::ip::address outboundAddress = getOutboundInterfaceIP();

	LOG_DEBUG("Advertising on interface " + outboundAddress.to_string());

	_socket->set_option(asio::ip::multicast::outbound_interface(outboundAddress.to_v4()));
	_socket->set_option(asio::ip::udp::socket::reuse_address(true));
	_socket->set_option(asio::socket_base::broadcast(true));

	// Set up the timer
	setTimer();

	// Run the context
	CommunicationEngine::instance()->runContext();

	_isRunning = true;
}

void Advertiser::advertise(const boost::system::error_code &e) {
	if(!_isRunning)
		return;
	
	// Broadcast
	LOG_DEBUG("Advertising on network");
	_socket->send_to(_outputBuffer.data(), _broadcastEndpoint);

	// Reset the timer
	setTimer();
}

void Advertiser::stopAdvertising() {
	if(!_isRunning)
		return;

	// Stop and erase timer
	_timer->cancel();
	delete _timer;
	_timer = nullptr;

	// Close the socket
	_socket->close();

	_isRunning = false;
}

void Advertiser::setTimer() {
	if(!_isRunning) {
		// Create the timer
		_timer = new asio::deadline_timer(CommunicationEngine::instance()->getContext());
	}

	// Set up the timer
	_timer->expires_from_now(boost::posix_time::seconds(1));
	_timer->async_wait(boost::bind(&Advertiser::advertise, this, boost::asio::placeholders::error));
}

asio::ip::address Advertiser::getOutboundInterfaceIP() {
	// Find the outbound interfaces
	asio::ip::udp::resolver resolver(CommunicationEngine::instance()->getContext());
	asio::ip::udp::resolver::query query(asio::ip::host_name(), "");
	asio::ip::udp::resolver::iterator it = resolver.resolve(query);

	asio::ip::address interfaceIPAdress;

	std::vector<asio::ip::address> interfaces;

	// Select the first IPv4 interface and use it
	while(it != boost::asio::ip::udp::resolver::iterator()) {
		asio::ip::address interface = (it++)->endpoint().address();
		if(interface.is_v4()) {
			interfaces.push_back(interface);
		}
	}


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
	LOG_INFO("Please select interface to use for advertising on the network:");

	std::string queryInteraces = "";
	for(int i = 0; i < interfaces.size(); ++i) {
		queryInteraces += "(" + std::to_string(i) + ") " + interfaces[i].to_string() + "; ";
	}

	LOG_INFO(queryInteraces);
	std::cout << ">> ";
	std::string selectedInterface;
	std::cin >> selectedInterface;

	return interfaces[std::atoi(selectedInterface.c_str())];
}

Advertiser::~Advertiser() {
	// Properly close everything if needed
	stopAdvertising();

	// Free used memory
	delete _socket;
}
