//
//  PBReceiver.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-03.
//

#ifndef PBReceiver_hpp
#define PBReceiver_hpp

#include <iostream>
#include <vector>
#include <mutex>

#include "../../common.hpp"
#include "../../Utils/thread.hpp"

#include "../Exchanges/Socket.hpp"
#include "../Exchanges/SocketDelegate.hpp"
#include "../Discovery/Browser.hpp"

#include "../../Utils/Arena.hpp"
#include "../../Structs/Body.hpp"

namespace pb {
namespace network {

class PBReceiver;

class PBReceiverObserver {
public:
	virtual void receiverDidConnect(PBReceiver *) = 0;
	virtual void receiverDidUpdate(PBReceiver *) = 0;
	virtual void receiverDidClose(PBReceiver *) = 0;
};

class PBReceiver: public SocketDelegate {
public:

	PBReceiver() {
		_socket.delegate = this;

		_browser.onReceive = [&] (const Endpoint &remote) {
			if(_socket.getStatus() != SocketStatus::ready)
				_socket.connectTo(remote.ip, serverPortReceiver);
		};
	}

	~PBReceiver() {
		delete _internalThread;
	}

	// MARK: - Observers

	inline void addObserver(PBReceiverObserver * observer) {
		_observers.push_back(observer);
	}

	inline void removeObserver(PBReceiverObserver * observer) {
		std::remove(_observers.begin(), _observers.end(), observer);
	}

	// MARK: - Lifecycle

	inline void open() {
		_browser.startBrowsing(discoveryPortReceiver);

		_internalThread = new std::thread(&PBReceiver::parseBodies, this);
	}

	void close() {
		_browser.stopBrowsing();
		_socket.close();
	}

	// MARK: - Accessors

	inline bool isConnected() const {
		return _socket.getStatus() == SocketStatus::ready;
	}

	inline Arena * arena() {
		return &_arena;
	}

	// MARK: - Socket Delegate

	inline virtual void socketDidOpen(BaseSocket *) override {
		_browser.stopBrowsing();

		for (PBReceiverObserver * observer: _observers) {
			if(observer != nullptr)
				observer->receiverDidConnect(this);
		}
	}

	inline virtual void socketDidReceive(BaseSocket *, protobuf::Message * aMessage) override {
		messages::Datagram * datagram = dynamic_cast<messages::Datagram *>(aMessage);

		if(datagram->type() != messages::Datagram_Type_PARTIAL_BODY) {
			// Discard
			delete datagram;
			return;
		}

		// Unpack the datagram
		messages::PartialBody partialBody = messages::PartialBody();
		datagram->data().UnpackTo(&partialBody);

		const pb::bodyUID bodyUID = partialBody.uid();

		_arenaMutex.lock();

		// Do we have already a body for the current UID ?
		if(_bodies.find(bodyUID) != _bodies.end()) {
			// We already have this body.
			// Check if body is valid
			if(!partialBody.isvalid()) {
				// Erase body
				_bodies.erase(bodyUID);
				datagram->Clear();
				delete datagram;

				_arenaMutex.unlock();

				return updateObservers();
			}

			// Body is valid, merge the partial body in the body
			_bodies[bodyUID]->insertPartial(partialBody);

			datagram->Clear();
			delete datagram;

			_arenaMutex.unlock();

			return updateObservers();
		}

		// This looks like a new body, is it valid ?
		if(!partialBody.isvalid()) {
			// No, ignore
			datagram->Clear();
			delete datagram;

			_arenaMutex.unlock();

			return updateObservers();
		}

		// Body is good, insert it
		_bodies[bodyUID] = new Body(partialBody);

		_arenaMutex.unlock();

		updateObservers();
	}

	inline virtual void socketDidClose(BaseSocket *) override {
		_browser.startBrowsing(discoveryPortReceiver);

		for (PBReceiverObserver * observer: _observers) {
			if(observer != nullptr)
				observer->receiverDidClose(this);
		}
	}

	// MARK: - Properties
private:

	// MARK: Observers

	std::vector<PBReceiverObserver *> _observers;

	// MARK: Network

	Browser _browser;

	Socket<messages::Datagram> _socket;

	// MARK: Storage

	std::mutex _arenaMutex;

	std::map<bodyUID, Body *> _bodies;

	Arena _arena = Arena(&_bodies, &_arenaMutex);

	std::thread * _internalThread = nullptr;

	void parseBodies() {
		pb::thread::setName("pb.receiver.internal");

		while(true) {
			std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

			_arenaMutex.lock();

			// Check for outdated bodies
			for(auto it = _bodies.begin(); it != _bodies.end();) {
				it->second->inactivityCount += 1;

				if(it->second->inactivityCount > 30)
					it = _bodies.erase(it);
				else
					++it;
			}

			_arenaMutex.unlock();

			pb::thread::cadence(std::chrono::system_clock::now() - start, 15.0);
		}
	}

	void updateObservers() {
		for (PBReceiverObserver * observer: _observers) {
			if(observer != nullptr)
				observer->receiverDidUpdate(this);
		}
	}
};

} /* ::network */
} /* ::pb */

#endif /* PBReceiver_hpp */
