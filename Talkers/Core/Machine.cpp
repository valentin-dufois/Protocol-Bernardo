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

	// Store message
	// TODO:

	// Check behaviour value
	if(message->behaviour == -1) {
		sendMessage(nullptr);
		return;
	}

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

	if(output->isTreeEnd) {
		delete _tree;
		_tree = nullptr;
	}

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
	switch (value) {
		// Unimplemented variables fall back to manual mode
		case BODY_COUNT:
		case RECEIVED_QUESTIONS_COUNT:
			return getIntValueManually(value);
		// Default value stops program to catch errors asap
		default:
			std::cout << "*** " << accessibleValueLabel(value) << " is not an int" << std::endl;
			exit(1);
	}
}

double Machine::getDoubleValue(const AccessibleValues &value) {
	switch (value) {
			// Unimplemented variables fall back to manual mode
//		case :
//			return getDoubleValueManually(value);
			// Default value stops program to catch errors asap
		default:
			std::cout << "*** " << accessibleValueLabel(value) << " is not a double" << std::endl;
			exit(1);
	}
}

bool Machine::getBoolValue(const AccessibleValues &value) {
	switch (value) {
			// Unimplemented variables fall back to manual mode
//		case :
//			return getBoolValueManually(value);
			// Default value stops program to catch errors asap
		default:
			std::cout << "*** " << accessibleValueLabel(value) << " is not a boolean" << std::endl;
			exit(1);
	}
}

std::string Machine::getStringValue(const AccessibleValues &value) {
	switch (value) {
			// Unimplemented variables fall back to manual mode
//		case :
//			return getStringValueManually(value);
			// Default value stops program to catch errors asap
		default:
			std::cout << "*** " << accessibleValueLabel(value) << " is not a string" << std::endl;
			exit(1);
	}
}


// MARK: - Manual data access

int Machine::getIntValueManually(const AccessibleValues &value) {
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

double Machine::getDoubleValueManually(const AccessibleValues &value) {
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

bool Machine::getBoolValueManually(const AccessibleValues &value) {
	std::string input;

	std::cout << std::endl << "*** Manual input for " << accessibleValueLabel(value) << " (boolean: 0 = false; 1 = true) :" << std::endl;
	std::cout << "> ";

	std::cin >> input;
	std::cout << std::endl;

	return input != "0";
}

std::string Machine::getStringValueManually(const AccessibleValues &value) {
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
