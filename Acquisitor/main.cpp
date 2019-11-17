//
//  main.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-17.
//

#include <gflags/gflags.h>
#include <cstdlib>

#include "Core/Core.hpp"
#include "../Common/CommunicationEngine/CommunicationEngine.hpp"

int main(int argc, char * argv[]) {
	// Init the flags
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	CommunicationEngine::thisMachineType = Endpoint::Type::acquisitor;

	std::system("sh -c 'echo 256 > /sys/module/usbcore/parameters/usbfs_memory_mb");	

	// Init the app
	Core core;
	core.init();

	core.run();

	return 0;
}
