//
//  main.cpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include <iostream>

#include "../Common/Utils/flags.hpp"
#include "Core/Core.hpp"

int main(int argc, const char * argv[]) {

	po::options_description desc("Talkers");
	pb::flags::parse(argc, argv, desc);

	Core core;
	core.init();
	core.run();

	return 0;
}
