//
//  Core.hpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Core_hpp
#define Core_hpp

#include "../LayoutEngine/LayoutEngine.hpp"
#include "Network/NetworkManager.hpp"
#include "../TrackingEngine/TrackingEngine.hpp"

#include "../../Common/CommunicationEngine/Server.hpp"

struct RawBody;
class Socket;

class Core {
public:
	void init();

	void run();

	void onAcquisitor(AcquisitorClient * acquisitor);
private:

	bool _isRunning = true;

	NetworkManager _networkManager;

	LayoutEngine _layoutEngine;

	TrackingEngine _trackingEngine;

	Server _broadcastServer = Server(Endpoint::Type::broadcaster);

	// Events
	void onTrack(const std::map<pb::bodyUID, Body *> &bodies);
};

#endif /* Core_hpp */
