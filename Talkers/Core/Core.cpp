//
//  Core.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include <iostream>
#include <ctime>

#include "Core.hpp"
#include "../Behaviours/Message.hpp"


void Core::init() {

	// MARK: Network
	_PBReceiver.addObserver(this);
	_PBReceiver.open();

	_receiversServer.setEmissionFormat(pb::network::SocketFormat::json);
	_receiversServer.open();

	// MARK: Machines

	_machineA.label = "A";
	_machineB.label = "B";

	_machineA.delegate = this;
	_machineB.delegate = this;

	_machineA.setArena(_PBReceiver.arena());
	_machineB.setArena(_PBReceiver.arena());

	// Init rand
	srand(static_cast<unsigned> (time(0)));
}

void Core::run() {
	_isRunning = true;

	manualStart();


	do {
		std::unique_lock<std::mutex> lk(_talkMutex);
		_cv.wait(lk, [&]{ return _nextMessage != nullptr; });

		talk();

		lk.unlock();

	} while(_isRunning);
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

		message->values.insert_or_assign(varName, std::atof(varVal.c_str()));
	}

	_nextMessage = message;
}

void Core::talk() {
	do {
		// Switch current machine;
		if(_currentMachine == &_machineB)
			_currentMachine = &_machineA;
		else
			_currentMachine = &_machineB;

		_currentMachine->onMessage(_nextMessage);

		// Here, the current machine has updated its next message, if there is one, send it to the network
		if(_nextMessage != nullptr)
			send(_nextMessage);

	} while (_nextMessage != nullptr);
}

void Core::terminate() {
	_PBReceiver.close();
}

Core::~Core() {
	terminate();
}


// MARK: - Receiver Delegate

void Core::receiverDidConnect(pb::network::PBReceiver *) {

}

void Core::receiverDidUpdate(pb::network::PBReceiver *) {
	if(!_machineA.executeWatchers())
		_machineB.executeWatchers();
}

void Core::receiverDidClose(pb::network::PBReceiver *) {

}


// MARK: - Machine Delegate

void Core::machineSendsMessage(Machine *, Message * aMessage) {
	if(_nextMessage != nullptr)
		delete _nextMessage;

	_nextMessage = aMessage;
}

void Core::machineSaysSomething(Machine *, const std::string &caption) {
	Message message;
	message.caption = caption;
	message.behaviour = -1;

	send(&message);
}

void Core::machineExecuteEvent(Machine * aMachine, const Event &event) {
	Message * message = new Message();
	message->behaviour = event.behaviour;
	message->values = event.values;

	if(aMachine->label == "A")
		_currentMachine = &_machineB;
	else
		_currentMachine = &_machineA;

	_talkMutex.lock();

	_nextMessage = message;

	_talkMutex.unlock();
	_cv.notify_all();
}

void Core::send(Message * message) {
	messages::Machine machineMessage;

	// Fill in message content
	machineMessage.set_label(_currentMachine->label);
	machineMessage.set_caption(message->caption);

	// Add the machine state


	// send
	_receiversServer.sendToAll(&machineMessage);
}
