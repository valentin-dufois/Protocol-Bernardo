//
//  Core.cpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-20.
//

#include <boost/bind.hpp>
#include <pthread.h>

#include "Core.hpp"
#include "../libraries.hpp"

#include "../../Common/Utils.hpp"
#include "../../Common/Network.hpp"

namespace pb {
namespace tracker {

Core * Core::_instance = nullptr;

void Core::init() {
	// Name our main thread
	pb::thread::setName("pb.tracker.main");

	// Setup the Pose estimation engine
	_poseEngine.onRawBodies = [&] (const std::set<pb::RawBody *, pb::RawBodyComparator> &rawBodies) {
		onRawBodies(rawBodies);
	};
	_poseEngine.start();

	_socket.delegate = this;

	// Start browsing
	_browser.onReceive = [&] (const network::Endpoint &endpoint) {
		_browser.stopBrowsing();
		_socket.connectTo(endpoint.ip, network::serverPortTracker);
	};

	_browser.startBrowsing(network::discoveryPortTracker);
}

void Core::run() {
	while(true) {
		std::string input;
		std::cin >> input;
	}
}

void Core::terminate() {
	delete _instance;
}

void Core::onRawBodies(const std::set<pb::RawBody *, pb::RawBodyComparator> &rawBodies) {

	if(_socket.getStatus() != network::SocketStatus::ready)
		return;

	network::messages::Datagram * datagram;

	for(pb::RawBody * rawBody: rawBodies) {
		datagram = network::makeDatagram(network::messages::Datagram_Type_RAW_BODY, (network::messages::RawBody)*rawBody);

		_socket.send(datagram);

		datagram->Clear();
		delete datagram;
	}
}

Core::~Core() {}

void Core::socketDidClose(network::Socket *) {
	_browser.startBrowsing(network::discoveryPortTracker);
}

} /* ::tracker */
} /* ::pb */
