//
//  Browser.cpp
//  NetworkEngine
//
//  Created by Valentin Dufois on 2019-09-11.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include <boost/bind.hpp>

#include "Browser.hpp"

#include "../NetworkEngine.hpp"
#include "../Messages/messages.hpp"
#include "../../Utils/Log.hpp"

namespace pb {
namespace network {

void Browser::startBrowsing(const NetworkPort &port) {
	if(_isRunning)
		return;

	_anyEndpoint = asio::ip::udp::endpoint(asio::ip::address_v4::any(), port);

	// Create the socket
	_socket = new asio::ip::udp::socket(Engine::instance()->getContext());

	_socket->open(asio::ip::udp::v4());
	_socket->set_option(asio::socket_base::broadcast(true));

	// Open the socket
	_socket->bind(_anyEndpoint);

	// Bind the handler
	_socket->async_receive_from(asio::buffer(_receptionBuffer), _anyEndpoint, [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {
		handleReceive(error, bytes_transferred);
	});

	// Run the thread on the background
	Engine::instance()->runContext();

	_isRunning = true;

	LOG_INFO("Browsing on port " + std::to_string(_anyEndpoint.port()));
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

	// Are we still running ?
	if(!_isRunning)
		return;

	// Prepare for another receive
	_socket->async_receive_from(asio::buffer(_receptionBuffer), _anyEndpoint, [&] (const boost::system::error_code &error, std::size_t bytes_transferred) {
		handleReceive(error, bytes_transferred);
	});

	// Run the thread on the background
	Engine::instance()->runContext();
}

void Browser::stopBrowsing() {
	if(!_isRunning)
		return;

	// Close the socket
	_socket->close();
	delete _socket;
	_socket = nullptr;

	_isRunning = false;
}

Browser::~Browser() {
	// End operations
	stopBrowsing();

	// Free used memory
	delete _socket;
}

} /* network */
} /* pb */
