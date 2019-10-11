//
//  main.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-17.
//

#include "Core/Core.hpp"

#include "../Common/CommunicationEngine/CommunicationEngine.hpp"

int main(int argc, const char * argv[]) {
	CommunicationEngine::thisMachineType = Endpoint::Type::acquisitor;

	// Init the app
	Core core;
	core.init();

	core.run();

	return 0;
}
