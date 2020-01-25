//
//  Core.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Core_hpp
#define Core_hpp

#include <mutex>
#include <condition_variable>

#include "Machine.hpp"
#include "MachineDelegate.hpp"
#include "../Behaviours/Message.hpp"

#include "../../Common/Network.hpp"
#include "../../Common/Network/PB/PBReceiver.hpp"

class Core: public pb::network::PBReceiverObserver,
			public MachineDelegate {
	// MARK: - Lifecycle
public:

	Core(): _receiversServer(pb::network::serverPortTalker, pb::network::discoveryPortTalker) {}

	/// Initialize all required components
	void init();

	/// Execute the application
	void run();

private:

	/// Used when testing, to manually trigger a behaviour at the start of the app.
	void manualStart();

	/// Makes the machines 'talks' until one of them has nothing else to say.
	void talk();

public:

	/// Properly ends the app
	void terminate();

	~Core();

	// MARK: - PB Receiver Observer

	virtual void receiverDidConnect(pb::network::PBReceiver *) override;

	virtual void receiverDidUpdate(pb::network::PBReceiver *) override;

	virtual void receiverDidClose(pb::network::PBReceiver *) override;

	// MARK: - Machine Delegate

	virtual void machineSaysSomething(Machine *, const std::string &caption) override;

	virtual void machineExecuteEvent(Machine * aMachine, const Event &event) override;

	// MARK: - Properties
private:

	bool _isRunning = false;

	Message * _nextMessage = nullptr;

	// MARK: Network

	/// Used to receive information from PB
	pb::network::PBReceiver _PBReceiver;

	pb::network::Server _receiversServer;

	void send(Message * message);

	// MARK: Machines

	Machine _machineA = Machine(_PBReceiver.arena());
	Machine _machineB = Machine(_PBReceiver.arena());

	Machine * _currentMachine = &_machineB;

	std::mutex _talkMutex;
	std::condition_variable _cv;
};

#endif /* Core_hpp */
