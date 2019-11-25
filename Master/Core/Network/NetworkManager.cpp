//
//  NetworkManager.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include "NetworkManager.hpp"

#include "TrackerClient.hpp"

namespace pb {
namespace master {

NetworkManager::NetworkManager():
_terminalServer(Endpoint::master),
_trackerBrowser(Endpoint::tracker),
_receiversServer(Endpoint::receiver)
{
	// Set up the browsers
	_trackerBrowser.onReceive = [&] (const Endpoint &endpoint) {
		connectTo(endpoint);
	};}

void NetworkManager::startActivities() {
	_trackerBrowser.startBrowsing();
	_receiversServer.advertise();

	_receiversServer.open();
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
		case Endpoint::Type::tracker: connectToTracker(endpoint); break;
		default:
			LOG_WARN("Trying to connect to an unsupported enpoint");
			return; // Other endpoint are not supported here
	}
}

void NetworkManager::connectToTracker(const Endpoint &endpoint) {

	LOG_DEBUG("Building Tracker client for " + endpoint.name);

	TrackerClient * tracker = new TrackerClient();

	// On connection successful, store the endpoint in our list of connected ones to
	// prevent multiple connection on the same endpoint for the same service
	tracker->onConnected = [&, tracker] (const Endpoint &server) {
		_connectedEndpoints.push_back(server);
		_connectedTrackers.push_back(tracker);

		// Start the body stream
		tracker->requestBodyStream();
	};

	// On close, remove the tracker fromn the tracker array
	tracker->onClose = [&] (TrackerClient * closingTracker) {
		_connectedEndpoints.erase(std::find(_connectedEndpoints.begin(), _connectedEndpoints.end(), closingTracker->getRemote()));

		_connectedTrackers.erase(std::find(_connectedTrackers.begin(), _connectedTrackers.end(), closingTracker));
	};

	// Open the connection
	tracker->connectTo(endpoint);

	if(onTracker)
		onTracker(tracker);
}

void NetworkManager::sendToTerminal(protobuf::Message * message) {
	_terminalServer.sendToAll(message);
}

void NetworkManager::
sendToReceivers(protobuf::Message * message) {
	_receiversServer.sendToAll(message);
}

} /* ::master */
} /* ::pb */
