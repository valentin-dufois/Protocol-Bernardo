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

// MARK: - Inputs

Message * Machine::onMessage(Message * message) {
	if(message == nullptr)
		return nullptr;

	// Remember the message
	storeCaption(message->caption);

	if(message->isTreeEnd && _tree != nullptr) {
		delete _tree;
		_tree = nullptr;
	}

	// Check behaviour value
	if(message->behaviour == -1) {
		return nullptr;
	}

	// Get the message behaviour
	Behaviour * behaviour = Behaviour::get(message->behaviour);

	// Do we have a valid behaviour ?
	if(behaviour == nullptr) {
		onError("Invalid behaviour ID : " + std::to_string(message->behaviour));
		return nullptr;
	}

	if(behaviour->isTreeStart) {
		if(_tree != nullptr && !behaviour->forceStart) {
			delete behaviour;
			onError("Behaviour " + std::to_string(behaviour->id) + " is not marked as tree start but a tree is already present.");
			return nullptr;
		}

		if(_tree != nullptr)
			delete _tree;

		_tree = new Tree(behaviour->treeID);
	}

	if(!behaviour->importMessage(message)) {
		delete behaviour;
		onError("Error while importing message on behaviour " + std::to_string(behaviour->id));
		return nullptr;
	}

	if(!behaviour->execute(this)) {
		delete behaviour;
		onError("Error while executing behaviour " + std::to_string(behaviour->id));
		return nullptr;
	}

	// Get the behaviour results
	Output * output = behaviour->getOutput();

	if(output == nullptr) {
		// No output, end here
		return nullptr;
	}
	
	Message * outMessage = output->getMessage();

	if(output->isTreeEnd) {
		delete _tree;
		_tree = nullptr;
	}

	// Send the message and pause the thread as needed
	saySomething(outMessage->caption, output->getDelay());

	delete output;

	// Return the message so it can be sent to the other machine
	return outMessage;
}

void Machine::storeCaption(const std::string &caption) {
	_receptionHistory.push_back(caption);
}

void Machine::saySomething(const std::string &caption, const double &aDelay) {
	// Pause the thread if needed
	std::chrono::duration<double, std::ratio<1>> delay(aDelay);
	std::this_thread::sleep_for(delay);

	std::cout << "[" << label << "] " << caption << std::endl;

	delegate->machineSaysSomething(this, caption);
}

messages::Talkers Machine::getOutputMessage() {
	messages::Talkers message;

	// Set label
	message.set_label(this->label);

	// Add the machine state
	message.set_bodycount((int)_arena->count());
	message.set_averageactivity(_arena->averageMoveSpeed());
	message.set_maximumactivity( std::get<1>(_arena->mostActiveBody()));
	message.set_tree(_tree != nullptr);

	return message;
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
	// Store UIDS
	for(pb::Body * body: arena()->getSubset()) {
		_bodyUIDHistory.insert(body->uid);
	}

	// Execute each watchers
	for(Watcher * watcher: _watchers) {
		watcher->watch(_arena);

		if(!watcher->hasFoundEvent())
			continue;

		Event event = watcher->getEvent();
		_events.push_back(event);

		// Keep only the last 100 events
		if(_events.size() > 100)
			_events.pop_front();

		if(_tree == nullptr) {
			// Dispatch
			LOG_DEBUG("Event " + event.name);
			delegate->machineExecuteEvent(this, event);
			return true;
		}
	}

	return false;
}

// MARK: - Properties

void Machine::onError(const std::string &desc) {
	std::cout << "[" << label << "] " << "*** Error";
	std::cout << "[" << label << "] " << desc;
	std::cout << "[" << label << "] " << "*********";
}
