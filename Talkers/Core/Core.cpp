//
//  Core.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Core.hpp"
#include "../Behaviours/Message.hpp"

#include <iostream>

void Core::init() {
	_machineA.label = "A";
	_machineB.label = "B";

	_machineA.sendMessage = [&] (Message * message) {
		_machineB.onMessage(message);
		delete message;
	};

	_machineB.sendMessage = [&] (Message * message) {
		_machineA.onMessage(message);
		delete message;
	};
}

void Core::run() {
	_isRunning = true;

	std::string bID, inputCount;

	while (_isRunning) {
		Message * message = new Message();

		std::cout << "Behaviour ID to start : ";
		std::cin >> bID;

		std::cout << "Add incoming variables ? (How Many ?): ";
		std::cin >> inputCount;

		for(int i = 0; i < std::atoi(inputCount.c_str()); ++i) {
			std::string varName;
			std::cout << "Variable " << i << " name : ";
			std::cin >> varName;

			std::string varVal;
			std::cout << "Variable " << i << " value : ";
			std::cin >> varVal;

			message->values[varName] = std::atof(varVal.c_str());
		}

		message->behaviour = std::atoi(bID.c_str());

		_machineA.onMessage(message);

		delete message;

		std::cout << std::endl;
	}
}

void Core::terminate() {

}

Core::~Core() {
	terminate();
}
