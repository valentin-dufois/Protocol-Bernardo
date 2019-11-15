//
//  Core.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#include "Core.hpp"

#include "../libraries.hpp"

#include "../../Common/Utils/Log.hpp"
#include "../../Common/Utils/thread.hpp"
#include "../../Common/CommunicationEngine/CommunicationEngine.hpp"
#include "../../Common/CommunicationEngine/Discovery/Advertiser.hpp"

#include "AcquisitorServer.hpp"

#include <boost/bind.hpp>
#include <pthread.h>

Core * Core::_instance = nullptr;

void Core::init() {
	// Name our main thread
	pb::setThreadName("pb.acquisitor.main");

	// Set up the acquisitor server
	LOG_INFO("Starting up the acquisitor server");
	_server = new AcquisitorServer(Endpoint::Type::acquisitor);

	// Setup the Pose estimation engine
	_poseEngine.onRawBodies = [&] (const std::set<RawBody *, RawBodyComparator> & rawBodies) {
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

void Core::onRawBodies(const std::set<RawBody *, RawBodyComparator> &rawBodies) {
	_server->sendRawBodies(rawBodies);
}

Core::~Core() {
	delete _server;
}

// MARK: - Communication
