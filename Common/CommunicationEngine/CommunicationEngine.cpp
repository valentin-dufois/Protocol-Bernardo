//
//  CommunicationEngine.cpp
//  CommunicationEngine
//
//  Created by Valentin Dufois on 2019-09-09.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "CommunicationEngine.hpp"
#include "../Utils/thread.hpp"

#include <pthread.h>
// MARK: - Static informations

Endpoint::Type CommunicationEngine::thisMachineType = Endpoint::Type::undefined;

CommunicationEngine * CommunicationEngine::_instance = nullptr;

void CommunicationEngine::runContext() {
	if(_executionThread != nullptr && _executionThread->joinable()) {
		// We have a thread, meaning the context is running, do nothing
		return;
	}

	// No thread, create it and run it
	_executionThread = new std::thread([&] () {
		pb::setThreadName("pb.communication-engine");

		_ioContext.restart();
		_ioContext.run();

		_executionThread->detach();
	});
}
