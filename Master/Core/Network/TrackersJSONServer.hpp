//
//  TrackersJSONServer.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2020-02-05.
//

#ifndef TrackersJSONServer_hpp
#define TrackersJSONServer_hpp

#include "../../../Common/Network.hpp"

using namespace pb::network;

namespace pb {

class RawBody;

namespace master {

class TrackingEngine;

class TrackersJSONServer: public Server<pb::network::messages::RawBody> {
public:
	TrackersJSONServer(): Server(serverPortTrackerJSON, discoveryPortTrackerJSON, Endpoint::tracker) {
		Server::setEmissionFormat(json);
	}

	TrackingEngine * trackingEngine;

protected:
	void socketDidOpen(BaseSocket * newSocket) override;

	void socketDidClose(BaseSocket * closedSocket) override;

private:

	void socketDidReceive(BaseSocket * socket, protobuf::Message * datagram) override;
};

} /* ::master */
} /* ::pb */

#endif /* TrackersJSONServer_hpp */
