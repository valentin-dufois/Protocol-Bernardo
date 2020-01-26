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
#include "../../Common/Utils/thread.hpp"

void Core::init() {
	pb::thread::setName("prisme.talkers.main");

	// MARK: Network
	_PBReceiver.open();

	_receiversServer.setEmissionFormat(pb::network::SocketFormat::json);
	_receiversServer.open();

	// MARK: Machines
	_machineA.label = "A";
	_machineB.label = "B";

	_machineA.delegate = this;
	_machineB.delegate = this;
	
	// Init rand
	srand((unsigned int)time(NULL));
}

void Core::run() {
	_isRunning = true;

#ifdef DEBUG
	//  manualStart();
#endif

	// Start the watchers thread
	_watchersThread = new std::thread(&Core::watchersThread, this);

	// Start our main loop
	do {
		std::unique_lock<std::mutex> lk(_talkMutex);

		// Wait here until there is a message to send
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

		message->values[varName] = std::atof(varVal.c_str());
	}

	_nextMessage = message;
}

void Core::talk() {
	do {
		Message * message = _currentMachine->onMessage(_nextMessage);

		delete _nextMessage;
		_nextMessage = message;

		// Switch current machine;
		_currentMachine = _currentMachine == &_machineB
			? &_machineA
			: &_machineB;

	} while (_nextMessage != nullptr);
}

void Core::terminate() {
	_PBReceiver.close();
}

Core::~Core() {
	terminate();
}


// MARK: - Machine Delegate

void Core::machineSaysSomething(Machine * aMachine, const std::string &caption) {
	if(aMachine->label == "A")
		_machineB.storeCaption(caption);
	else
		_machineA.storeCaption(caption);

	messages::Talkers machineMessage = aMachine->getOutputMessage();

	// Fill in message content
	machineMessage.set_type("caption");
	machineMessage.set_caption(caption);

	// Send
	_receiversServer.sendToAll(&machineMessage);
}

void Core::machineExecuteEvent(Machine * aMachine, const Event &event) {
	Message * message = new Message();
	message->behaviour = event.behaviour;
	message->values = event.values;
	message->isTreeEnd = false;

	_currentMachine = aMachine;
	_nextMessage = message;

	// Send the event
	messages::Talkers machineMessage = aMachine->getOutputMessage();

	// Fill in message content
	machineMessage.set_type("event");
	machineMessage.set_event(event.name);

	_receiversServer.sendToAll(&machineMessage);

	_cv.notify_all();
}

void Core::watchersThread() {
	pb::thread::setName("prisme.talkers.watchers");

	while (_isRunning) {
		std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();

		// Execute the watchers on each machine alternatively
		if(_lastChecked == "B") {
			_machineA.executeWatchers();
			_lastChecked = "A";
			return;
		} else {
			_machineB.executeWatchers();
			_lastChecked = "B";
		}

		std::chrono::system_clock::time_point endTime = std::chrono::system_clock::now();

		pb::thread::cadence(endTime - startTime, 8);
	}
}
