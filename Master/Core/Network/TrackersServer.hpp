//
//  TrackersServer.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-30.
//

#ifndef TrackersServer_hpp
#define TrackersServer_hpp

#include "../../../Common/Network.hpp"

using namespace pb::network;

namespace pb {

class RawBody;

namespace master {

class TrackingEngine;

class TrackersServer: public Server {
public:
	TrackersServer(): Server(serverPortTracker, discoveryPortTracker, Endpoint::tracker) {}

	TrackingEngine * trackingEngine;

protected:
	void socketDidOpen(Socket * newSocket) override;

	void socketDidClose(Socket * closedSocket) override;

private:

	void socketDidReceive(Socket * socket, messages::Datagram * datagram) override;

	void onBodyStream(const protobuf::Any * data);
};

} /* ::master */
} /* ::pb */

#endif /* TrackersServer_hpp */
