//
//  main.cpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-17.
//

#include <csignal>

#include "../Common/Network.hpp"

#include "libraries.hpp"
#include "Core/Core.hpp"

void signalHandler(int signum) {
	// Properly terminate the application services
	pb::tracker::Core::instance()->terminate();

	exit(signum);
}

int main(int argc, char * argv[]) {

	// Register our closing mechanisms
	signal(SIGINT, signalHandler);

	// Init the flags
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	// Set the application type on the Network
	pb::network::Engine::thisMachineType = pb::network::Endpoint::Type::tracker;

	// Init the app
	pb::tracker::Core::instance()->init();

	// Start the runLoop
	pb::tracker::Core::instance()->run();

	return 0;
}
