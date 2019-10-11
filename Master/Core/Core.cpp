//
//  Core.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include "Core.hpp"

#include <boost/asio.hpp>

void Core::init() {
	_networkManager.startActivities();
	_networkManager.setLayoutEngine(&_layoutEngine);
}

void Core::run() {
	// Main loop
	while(_isRunning) { }
}


