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

	// MARK: Network
	_receiver.addObserver(this);
	_receiver.open();

	// MARK: Machines

	_machineA.label = "A";
	_machineB.label = "B";

	_machineA.sendMessage = std::bind(&Core::onMessage, this, std::placeholders::_1);
	_machineB.sendMessage = std::bind(&Core::onMessage, this, std::placeholders::_1);
}

void Core::run() {
	_isRunning = true;

	manualStart();

	do {
		if(_lastMachine == &_machineB)
			_lastMachine = &_machineA;
		else
			_lastMachine = &_machineB;

		_lastMachine->onMessage(_nextMessage);
	} while (_nextMessage != nullptr);
}

void Core::manualStart() {

	std::string bID, inputCount;

	Message * message = new Message();

	std::cout << std::endl << "*** MANUAL MODE ***" << std::endl;

	std::cout << "*** Behaviour ID to start : ";
	std::cin >> bID;

	message->behaviour = std::atoi(bID.c_str());

	std::cout << "*** Add incoming variables ? (How Many ?): ";
	std::cin >> inputCount;

	for(int i = 0; i < std::atoi(inputCount.c_str()); ++i) {
		std::string varName;
		std::cout << "*** Variable " << i << " name : ";
		std::cin >> varName;

		std::string varVal;
		std::cout << "*** Variable " << i << " value : ";
		std::cin >> varVal;

		message->values[varName] = std::atof(varVal.c_str());
	}

	_nextMessage = message;
}

void Core::terminate() {
	_receiver.close();
}

Core::~Core() {
	terminate();
}

// MARK: - Receiver Delegate

void Core::receiverDidConnect(pb::network::PBReceiver *) {

}

void Core::receiverDidReceive(pb::network::PBReceiver *, pb::network::messages::TrackedBodies *) {

}

void Core::receiverDidClose(pb::network::PBReceiver *) {

}



void Core::onMessage(Message * message) {
	if(_nextMessage != nullptr)
		delete _nextMessage;

	_nextMessage = message;
}
