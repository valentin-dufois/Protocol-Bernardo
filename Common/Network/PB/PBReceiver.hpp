//
//  PBReceiver.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-03.
//

#ifndef PBReceiver_hpp
#define PBReceiver_hpp

#include <vector>
#include <mutex>

#include "../../common.hpp"

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
	}

	void close() {
		_browser.stopBrowsing();
		_socket.close();
	}

	// MARK: - Accessors

	inline bool isConnected() const {
		return _socket.getStatus() == SocketStatus::ready;
	}

	inline Arena arena() {
		return Arena(&_bodies, &_arenaMutex);
	}

	// MARK: - Socket Delegate

	inline virtual void socketDidOpen(Socket *) override {
		_browser.stopBrowsing();

		for (PBReceiverObserver * observer: _observers) {
			if(observer != nullptr)
				observer->receiverDidConnect(this);
		}
	}

	inline virtual void socketDidReceive(Socket *, messages::Datagram * datagram) override {
		if(datagram->type() != messages::Datagram_Type_TRACKED_BODIES) {
			// Discard
			delete datagram;
			return;
		}

		// Unpack the datagram
		messages::TrackedBodies trackedBodies = messages::TrackedBodies();
		datagram->data().UnpackTo(&trackedBodies);

		int bodiesCount = trackedBodies.bodies_size();

		_arenaMutex.lock();

		// For each received body
		for(int i = 0; i < bodiesCount; ++i) {
			Body * body = new Body(trackedBodies.bodies(i));

			// Is there already a body with the same uid in the buffer ?
			if(_bodies.find(body->uid) != _bodies.end()) {
				// A body is already stored, free it
				delete _bodies[body->uid];
			}

			if(!body->isValid) {
				_bodies.erase(body->uid);
				delete body;
				return;
			}

			// Store the body
			_bodies[body->uid] = body;
		}

		_arenaMutex.unlock();

		for (PBReceiverObserver * observer: _observers) {
			if(observer != nullptr)
				observer->receiverDidUpdate(this);
		}
	}

	inline virtual void socketDidClose(Socket *) override {
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

	Socket _socket;

	// MARK: Storage

	std::mutex _arenaMutex;

	std::map<bodyUID, Body *> _bodies;
};

} /* ::network */
} /* ::pb */

#endif /* PBReceiver_hpp */
