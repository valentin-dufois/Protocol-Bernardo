//
//  Core.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Core_hpp
#define Core_hpp

#include "Machine.hpp"
#include "Message.hpp"

#include "../../Common/Network.hpp"

class Core: public pb::network::PBReceiverObserver {
	// MARK: - Lifecycle
public:

	Core() = default;

	void init();

	void run();

private:

	void manualStart();

public:

	void terminate();

	~Core();

	// MARK: - Receiver Delegate

	virtual void receiverDidConnect(pb::network::PBReceiver *) override;

	virtual void receiverDidReceive(pb::network::PBReceiver *, pb::network::messages::TrackedBodies *) override;

	virtual void receiverDidClose(pb::network::PBReceiver *) override;

	// MARK: - Properties
private:

	bool _isRunning = false;

	// MARK: Network

	pb::network::PBReceiver _receiver;

	Message * _nextMessage = nullptr;

	void onMessage(Message * message);

	// MARK: Machines

	Machine _machineA;
	Machine _machineB;

	Machine * _lastMachine = &_machineB;
};

#endif /* Core_hpp */
