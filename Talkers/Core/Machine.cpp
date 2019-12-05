//
//  Machine.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include <thread>
#include <iostream>
#include <cstdlib>

#include "Machine.hpp"

#include "../Behaviours/Output.hpp"
#include "../Behaviours/Behaviour.hpp"
#include "../Behaviours/Message.hpp"

// MARK: - In

void Machine::onMessage(Message * message) {
	if(message == nullptr)
		return;

	// Get the message behaviour
	Behaviour * behaviour = Behaviour::get(message->behaviour);

	// Do we have a valid behaviour ?
	if(behaviour == nullptr) {
		sendMessage(nullptr);
		return onError();
	}

	if(behaviour->isTreeStart) {
		if(_tree != nullptr && !behaviour->forceStart) {
			sendMessage(nullptr);
			delete behaviour;
			return onError();
		}

		if(_tree != nullptr)
			delete _tree;

		_tree = new Tree(behaviour->treeID);
	}

	if(!behaviour->importMessage(message)) {
		sendMessage(nullptr);
		delete behaviour;
		return onError();
	}

	if(!behaviour->execute(this)) {
		sendMessage(nullptr);
		delete behaviour;
		return onError();
	}

	// Get the behaviour results if needed
	Output * output = behaviour->getOutput();

	if(output == nullptr) {
		// No output
		sendMessage(nullptr);
		return;
	}
	
	Message * outMessage = output->getMessage();

	// Pause the thread if needed
	std::chrono::duration<double, std::ratio<1>> delay(output->getDelay());
	std::this_thread::sleep_for(delay);

	delete output;

	// Print the message
	print(outMessage->caption);

	// Send the message
	sendMessage(outMessage);
}

void Machine::print(const std::string out) {
	std::cout << "[" << label << "] " << out << std::endl;
}

void Machine::say(const std::string out) {
	std::cout << "[" << label << "] " << out << std::endl;
}

// MARK: - Data access

int Machine::getIntValue(const AccessibleValues &value) {
	int val;
	bool valueSet = false;
	std::string input;
	char * end;

	do {
		std::cout << std::endl << "*** Manual input for " << accessibleValueLabel(value) << " (int) :" << std::endl;
		std::cout << "> ";

		std::cin >> input;
		std::cout << std::endl;

		val = (int)std::strtol(input.c_str(), &end, 10);

		 if (errno != ERANGE)
			 valueSet = true;

	} while (!valueSet);

	return val;
}

double Machine::getDoubleValue(const AccessibleValues &value) {
	double val;
	bool valueSet = false;
	std::string input;
	char * end;

	do {
		std::cout << std::endl << "*** Manual input for " << accessibleValueLabel(value) << " (float) :" << std::endl;
		std::cout << "> ";

		std::cin >> input;
		std::cout << std::endl;

		val = std::strtod(input.c_str(), &end);

		if (errno != ERANGE)
			valueSet = true;

	} while (!valueSet);

	return val;
}

bool Machine::getBoolValue(const AccessibleValues &value) {
	std::string input;

	std::cout << std::endl << "*** Manual input for " << accessibleValueLabel(value) << " (boolean: 0 = false; 1 = true) :" << std::endl;
	std::cout << "> ";

	std::cin >> input;
	std::cout << std::endl;

	return input != "0";
}

std::string Machine::getStringValue(const AccessibleValues &value) {
	std::string input;

	std::cout << std::endl << "*** Manual input for " << accessibleValueLabel(value) << " (string) :" << std::endl;
	std::cout << "> ";

	std::cin >> input;
	std::cout << std::endl;

	return input;
}

// MARK: - Properties

void Machine::onError() {
	print("*** Error");
}
