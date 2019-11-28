//
//  main.cpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include <iostream>

#include "Core/Core.hpp"

int main(int argc, const char * argv[]) {

	Core core;
	core.init();
	core.run();

	return 0;
}
