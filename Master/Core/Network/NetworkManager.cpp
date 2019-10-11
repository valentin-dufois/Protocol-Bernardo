//
//  NetworkManager.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include "NetworkManager.hpp"

#include "AcquisitorClient.hpp"

NetworkManager::NetworkManager()
//:_masterServer(CommunicationEngine::thisMachineType)
{
	// Set up the browser
	_browser.onReceive = [&] (const Endpoint &endpoint) {
		connectTo(endpoint);
	};
}

void NetworkManager::startActivities() {
	_browser.startBrowsing();
}

void NetworkManager::connectTo(const Endpoint &endpoint) {
	// Check we are not already connected to this endpoint
	for(Endpoint &e: _connectedEndpoints) {
		// If the ip and type match, we are already connected to this endpoint: do nothing.
		if(e == endpoint)
			return;
	}

	LOG_INFO("Received advertising message from " + endpoint.name + " (" + endpoint.ip + ")");

	// This endpoint is new, let's dispatch it

	// Dispatch connection call
	switch (endpoint.type) {
		case Endpoint::Type::acquisitor: connectToAcquisitor(endpoint); break;
//		case Endpoint::Type::broadcaster: connectToBroadcaster(endpoint); break;
		default:
			LOG_WARN("Trying to connect to an unsupported enpoint");
			return; // Other endpoint are not supported here
	}
}

void NetworkManager::connectToAcquisitor(const Endpoint &endpoint) {

	LOG_DEBUG("Building Acquisitor client for " + endpoint.name);

	AcquisitorClient * acquisitor = new AcquisitorClient();
	// TODO: 
//	acquisitor->onBody = _masterServer.layoutEngine->onBody;

	// On connection successful, store the endpoint in our list of connected ones to
	// prevent multiple connection on the same endpoint for the same service
	acquisitor->onConnected = [&, acquisitor] (const Endpoint &server) {
		_connectedEndpoints.push_back(server);

		// Start the body stream
		acquisitor->requestBodyStream();
	};

	// On close, remove the acquisitor fromn the acquisitor array
	acquisitor->onClose = [&, endpoint] {
		_connectedEndpoints.erase(std::find(_connectedEndpoints.begin(), _connectedEndpoints.end(), endpoint));
	};

	// Open the connection
	acquisitor->connectTo(endpoint);

	if(onAcquisitor)
		onAcquisitor(acquisitor);
}
