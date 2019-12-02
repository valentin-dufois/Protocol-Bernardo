//
//  Machine.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include <thread>
#include <iostream>

#include "Machine.hpp"

#include "../Behaviours/Output.hpp"
#include "../Behaviours/Behaviour.hpp"
#include "../Behaviours/Message.hpp"

void Machine::onMessage(Message * message) {
	// Get the message behaviour
	Behaviour * behaviour = Behaviour::get(message->behaviour);

	// Do we have a valid behaviour ?
	if(behaviour == nullptr) {
		return onError();
	}

	if(behaviour->isTreeStart) {
		if(_tree != nullptr && !behaviour->forceStart) {
			delete behaviour;
			return onError();
		}

		if(_tree != nullptr)
			delete _tree;

		_tree = new Tree(behaviour->treeID);
	}

	if(!behaviour->importMessage(message)) {
		delete behaviour;
		return onError();
	}

	if(!behaviour->execute(this)) {
		delete behaviour;
		return onError();
	}

	// Get the behaviour results if needed
	Output * output = behaviour->getOutput();

	if(output == nullptr) {
		// No output
		return;
	}

	Message * outMessage = output->getMessage();

	// Pause the thread if needed
	std::chrono::duration<double, std::ratio<1>> delay(output->getDelay());
	std::this_thread::sleep_for(delay);

	// Print the message
	print(outMessage->caption);

	// Send the message
	sendMessage(outMessage);
}

void Machine::onError() {
	print("Error");
}

void Machine::print(const std::string out) {
	std::cout << "[" << label << "] " << out << std::endl;
}
