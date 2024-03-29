//
//  Core.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Core_hpp
#define Core_hpp

#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>

#include "Machine.hpp"
#include "MachineDelegate.hpp"
#include "../Behaviours/Message.hpp"

#include "../../Common/Network.hpp"
#include "../../Common/Network/PB/PBReceiver.hpp"

class Core: public MachineDelegate {
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

	// MARK: - Machine Delegate

	virtual void machineDidUpdate(Machine *) override;

	virtual void machineSaysSomething(Machine *, const std::string &caption) override;

	virtual void machineExecuteEvent(Machine * aMachine, const Event &event) override;

	// MARK: - Properties
private:

	std::atomic<bool> _isRunning = false;

	Message * _nextMessage = nullptr;

	// MARK: Network

	/// Used to receive information from PB
	pb::network::PBReceiver _PBReceiver;

	pb::network::Server<pb::network::messages::Datagram> _receiversServer;

	// MARK: Machines

	Machine _machineA = Machine(_PBReceiver.arena()->makeSubset({"touch00A1", "touch00A2"}));
	Machine _machineB = Machine(_PBReceiver.arena()->makeSubset({"touch00B1", "touch00B2"}));

	Machine * _currentMachine = &_machineB;

	std::mutex _talkMutex;
	std::condition_variable _cv;

	std::thread * _watchersThread = nullptr;

	void watchersThread();

	std::string _lastChecked = "B";
};

#endif /* Core_hpp */
