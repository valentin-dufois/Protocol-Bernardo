//
//  main.cpp
//  pb-Master
//
//  Created by Valentin Dufois on 2019-09-17.
//

#include <iostream>

#include "../Common/Utils/Log.hpp"

#include "Core/Core.hpp"

int main(int argc, const char * argv[]) {
	// Set app parameters
	Log::level = Log::Level::DEV;
	CommunicationEngine::thisMachineType = Endpoint::Type::master;

	// Start the core
	Core core;
	core.init();

	core.run();

	return 0;
}
