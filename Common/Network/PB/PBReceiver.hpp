//
//  PBReceiver.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-03.
//

#ifndef PBReceiver_hpp
#define PBReceiver_hpp

#include <vector>

#include "../Exchanges/Socket.hpp"
#include "../Exchanges/SocketDelegate.hpp"
#include "../Discovery/Browser.hpp"

namespace pb {
namespace network {

class PBReceiver;

class PBReceiverObserver {
public:
	virtual void receiverDidConnect(PBReceiver *) = 0;
	virtual void receiverDidReceive(PBReceiver *, messages::TrackedBodies *) = 0;
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
		messages::TrackedBodies * trackedBodies = new messages::TrackedBodies();
		datagram->data().UnpackTo(trackedBodies);

		for (PBReceiverObserver * observer: _observers) {
			if(observer != nullptr)
				observer->receiverDidReceive(this, trackedBodies);
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

};

} /* ::network */
} /* ::pb */

#endif /* PBReceiver_hpp */
