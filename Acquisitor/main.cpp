//
//  main.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-17.
//

#include <csignal>
#include <gflags/gflags.h>

#include "Core/Core.hpp"
#include "../Common/CommunicationEngine/CommunicationEngine.hpp"

void signalHandler(int signum) {
	// Properly terminate the application services
	Core::instance()->terminate();

	exit(signum);
}

int main(int argc, char * argv[]) {

	// Register our closing mechanisms
	signal(SIGINT, signalHandler);

	// Init the flags
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	// Set the application type on the CommunicationEngine
	CommunicationEngine::thisMachineType = Endpoint::Type::acquisitor;

	// Init the app
	Core::instance()->init();

	// Start the runLoop
	Core::instance()->run();

	return 0;
}
