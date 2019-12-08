//
//  main.cpp
//  pb-Master
//
//  Created by Valentin Dufois on 2019-09-17.
//

#include "../Common/Utils.hpp"
#include "../Common/Network.hpp"

#include "Core/Core.hpp"

void signalHandler(int signum) {
	LOG_INFO("Closing services...");

	// Properly terminate the application services
//	pb::master::Core::instance()->terminate();

	exit(signum);
}

int main(const int argc, const char * argv[]) {
	// Register our closing mechanisms
	signal(SIGINT, signalHandler);

	// Set app parameters
	po::options_description desc("pb-master");
	desc.add_options()("layout", po::value<std::string>(), "Layout to open on start");
	pb::flags::parse(argc, argv, desc);

	pb::thread::setName("pb.master");

	pb::network::Engine::thisMachineType = pb::network::Endpoint::Type::master;

	// Start the core
	pb::master::Core core;
	core.init();

	core.run();

	return 0;
}
