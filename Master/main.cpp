//
//  main.cpp
//  pb-Master
//
//  Created by Valentin Dufois on 2019-09-17.
//

#include <gflags/gflags.h>

#include "../Common/Utils.hpp"
#include "../Common/Network.hpp"

#include "Core/Core.hpp"

void signalHandler(int signum) {
	LOG_INFO("Closing services...");

	// Properly terminate the application services
//	pb::master::Core::instance()->terminate();

	exit(signum);
}

int main(int argc, char * argv[]) {
	// Register our closing mechanisms
	signal(SIGINT, signalHandler);

	// Set app parameters
	gflags::ParseCommandLineFlags(&argc, &argv, true);
	pb::thread::setName("pb.master");

	pb::Log::level = pb::Log::Level::DEV;
	pb::network::Engine::thisMachineType = pb::network::Endpoint::Type::master;

	// Start the core
	pb::master::Core core;
	core.init();

	core.run();

	return 0;
}
