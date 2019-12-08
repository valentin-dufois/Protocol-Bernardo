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
#include "MachineDelegate.hpp"

#include "../Behaviours/Output.hpp"
#include "../Behaviours/Behaviour.hpp"
#include "../Behaviours/Message.hpp"

// MARK: - In

void Machine::onMessage(Message * message) {
	if(message == nullptr)
		return;

	// Remember the message
	_receptionHistory.push_back(message->caption);

	// Check behaviour value
	if(message->behaviour == -1) {
		delegate->machineSendsMessage(this, nullptr);
		return;
	}

	// Get the message behaviour
	Behaviour * behaviour = Behaviour::get(message->behaviour);

	// Do we have a valid behaviour ?
	if(behaviour == nullptr) {
		delegate->machineSendsMessage(this, nullptr);
		return onError();
	}

	if(behaviour->isTreeStart) {
		if(_tree != nullptr && !behaviour->forceStart) {
			delegate->machineSendsMessage(this, nullptr);
			delete behaviour;
			return onError();
		}

		if(_tree != nullptr)
			delete _tree;

		_tree = new Tree(behaviour->treeID);
	}

	if(!behaviour->importMessage(message)) {
		delegate->machineSendsMessage(this, nullptr);
		delete behaviour;
		return onError();
	}

	if(!behaviour->execute(this)) {
		delegate->machineSendsMessage(this, nullptr);
		delete behaviour;
		return onError();
	}

	// Get the behaviour results if needed
	Output * output = behaviour->getOutput();

	if(output == nullptr) {
		// No output
		delegate->machineSendsMessage(this, nullptr);
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
	delegate->machineSendsMessage(this, outMessage);
}

void Machine::print(const std::string out) {
	std::cout << "[" << label << "] " << out << std::endl;
}

void Machine::say(const std::string out) {
	print(out);
	delegate->machineSaysSomething(this, out);
}

// MARK: - Manual getters

int Machine::getIntValue(const std::string &value) {
	int val;
	std::string input;
	char * end;

	do {
		std::cout << std::endl << "*** Manual input for " << value << " (int) :" << std::endl;
		std::cout << "> ";

		std::cin >> input;
		std::cout << std::endl;

		val = (int)std::strtol(input.c_str(), &end, 10);

		if (errno != ERANGE)
			return val;

		std::cout << "*** Error, please retry!" << std::endl;

	} while (true);
}

double Machine::getDoubleValue(const std::string &value) {
	double val;
	std::string input;
	char * end;

	do {
		std::cout << std::endl << "*** Manual input for " << value << " (float) :" << std::endl;
		std::cout << "> ";

		std::cin >> input;
		std::cout << std::endl;

		val = std::strtod(input.c_str(), &end);

		if (errno != ERANGE)
			return val;

		std::cout << "*** Error, please retry!" << std::endl;

	} while (true);
}

bool Machine::getBoolValue(const std::string &value) {
	std::string input;

	std::cout << std::endl << "*** Manual input for " << value << " (boolean: 0 = false; 1 = true) :" << std::endl;
	std::cout << "> ";

	std::cin >> input;
	std::cout << std::endl;

	return input != "0";
}


// MARK: - Watchers

bool Machine::executeWatchers() {
	for(Watcher * watcher: _watchers) {
		watcher->watch(&_arena);

		if(!watcher->hasFoundEvent())
			continue;

		Event event = watcher->getEvent();
		_events.push_back(event);

		// Keep only the last 100 events
		if(_events.size() > 100)
			_events.pop_front();

		if(_tree == nullptr) {
			// Dispatch
			delegate->machineExecuteEvent(this, event);
			return true;
		}
	}

	return false;
}

// MARK: - Properties

void Machine::onError() {
	print("*** Error");
}
