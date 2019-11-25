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

#include "TrackerServer.hpp"

#include "../../Common/Utils.hpp"
#include "../../Common/Network.hpp"

namespace pb {
namespace tracker {

Core * Core::_instance = nullptr;

void Core::init() {
	// Name our main thread
	pb::thread::setName("pb.tracker.main");

	// Set up the tracker server
	LOG_INFO("Starting up the tracker server");
	_server = new TrackerServer(network::Endpoint::Type::tracker);

	// Setup the Pose estimation engine
	_poseEngine.onRawBodies = [&] (const std::set<pb::RawBody *, pb::RawBodyComparator> & rawBodies) {
		onRawBodies(rawBodies);
	};
	
	_poseEngine.start();
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
	_server->sendRawBodies(rawBodies);
}

Core::~Core() {
	delete _server;
}

} /* ::tracker */
} /* ::pb */
