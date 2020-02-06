//
//  TrackersJSONServer.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2020-02-05.
//

#include "TrackersJSONServer.hpp"

#include "../../TrackingEngine/TrackingEngine.hpp"
#include "../../../Common/Structs/RawBody.hpp"

namespace pb {
namespace master {

void TrackersJSONServer::socketDidOpen(BaseSocket * socket) {
	Server::socketDidOpen(socket);
}

void TrackersJSONServer::socketDidReceive(BaseSocket * socket, protobuf::Message * aMessage) {
	Server::socketDidReceive(socket, aMessage);

	messages::RawBody * messageBody = dynamic_cast<messages::RawBody *>(aMessage);

	try{
		trackingEngine->onRawBody(new RawBody(*messageBody));
	} catch(std::runtime_error &e) {}
	
	delete messageBody;
}

void TrackersJSONServer::socketDidClose(BaseSocket * socket) {
	Server::socketDidClose(socket);
}

} /* ::master */
} /* ::pb */
