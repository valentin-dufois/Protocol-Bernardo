//
//  Browser.cpp
//  CommunicationEngine
//
//  Created by Valentin Dufois on 2019-09-11.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include <boost/bind.hpp>

#include "Browser.hpp"

#include "../CommunicationEngine.hpp"
#include "../../Messages/messages.hpp"
#include "../../Utils/Log.hpp"

Browser::Browser(): _anyEndpoint(asio::ip::udp::endpoint(asio::ip::address_v4::any(), _port)) { }

void Browser::startBrowsing() {
	if(_isRunning)
		return;

	// Create the socket
	_socket = new asio::ip::udp::socket(CommunicationEngine::instance()->getContext());

	_socket->open(asio::ip::udp::v4());
	_socket->set_option(asio::ip::udp::socket::reuse_address(true));
	_socket->set_option(asio::socket_base::broadcast(true));

	// Open the socket
	_socket->bind(_anyEndpoint);

	// Bind the handler
	_socket->async_receive_from(asio::buffer(_receptionBuffer), _anyEndpoint, [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {
		handleReceive(error, bytes_transferred);
	});

	// Run the thread on the background
	CommunicationEngine::instance()->runContext();

	_isRunning = true;
}

void Browser::handleReceive(const boost::system::error_code &error, std::size_t bytes_transferred) {

	// Get message as Endpoint
	_receptionMessage.ParseFromArray(_receptionBuffer.data(), (int)bytes_transferred);
	Endpoint endpoint = Endpoint(_receptionMessage, _anyEndpoint);

	// Clear the buffers
	_receptionMessage.Clear();
	_receptionBuffer.assign(0);

	// Propagate to handler
	if(onReceive)
		onReceive(endpoint);

	// Bind the handler
	_socket->async_receive_from(asio::buffer(_receptionBuffer), _anyEndpoint, [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {
		handleReceive(error, bytes_transferred);
	});
}

void Browser::stopBrowsing() {
	if(!_isRunning)
		return;

	// Close the socket
	_socket->close();

	_isRunning = false;
}

Browser::~Browser() {
	// End operations
	stopBrowsing();

	// Free used memory
	delete _socket;
}
