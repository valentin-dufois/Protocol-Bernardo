//
//  NetworkManager.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include "NetworkManager.hpp"

namespace pb {
namespace master {

NetworkManager::NetworkManager():
_trackersServer(),
_receiversServer(serverPortReceiver, discoveryPortReceiver, Endpoint::receiver),
_terminalServer()
{}

void NetworkManager::startActivities() {
	_trackersServer.advertise();
	_trackersServer.open();

	_receiversServer.advertise();
	_receiversServer.open();

	_terminalServer.advertise();
	_terminalServer.open();
}

void NetworkManager::sendToTerminal(protobuf::Message * message) {
	_terminalServer.sendToAll(message);
}

void NetworkManager::
sendToReceivers(protobuf::Message * message) {
	_receiversServer.sendToAll(message);
}

} /* ::master */
} /* ::pb */
