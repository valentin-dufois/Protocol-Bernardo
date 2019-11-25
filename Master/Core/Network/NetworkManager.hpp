//
//  NetworkManager.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef NetworkManager_hpp
#define NetworkManager_hpp

#include <vector>
#include <functional>

#include "../../../Common/Utils.hpp"
#include "../../../Common/Network.hpp"

#include "TerminalServer.hpp"

using namespace pb::network;

namespace pb {
namespace master {

class TrackerClient;
class LayoutEngine;
class TrackingEngine;

/// <#Description#>
class NetworkManager {
public:

	NetworkManager();

	/// Start all activities of the network manager
	void startActivities();

	/// Open a connection to the given endpoint. If successful, the corresponding callabacks will be called.
	/// @param endpoint The endpoint to connect to
	void connectTo(const Endpoint &endpoint);

	/// Called everytime a new Tracker is connected
	std::function<void(TrackerClient *)> onTracker;

	/// Called everytime a new Broadcaster is connected
//	std::function<void()> onBroadcaster;

	inline void setLayoutEngine(LayoutEngine * layoutEngine) {
		_terminalServer.layoutEngine = layoutEngine;
	}


	inline void setTrackingEngine(TrackingEngine * trackingEngine) {
		_terminalServer.trackingEngine = trackingEngine;
	}

	void sendToTerminal(protobuf::Message * message);

	void sendToReceivers(protobuf::Message * message);

private:

	/// Used to find Trackers on the network
	Browser _trackerBrowser;

	/// The list of endpoints we are connected to
	std::vector<Endpoint> _connectedEndpoints;

	/// The list of connected Trackers
	std::vector<TrackerClient *> _connectedTrackers;

	/// The list of connected Receiverrs
	std::vector<Socket *> _connectedReceivers;

	/// Establishes a connection to the given Tracker
	void connectToTracker(const Endpoint &endpoint);

	/// The master server
	TerminalServer _terminalServer;

	/// The receivers server
	Server _receiversServer;

};

} /* ::master */
} /* ::pb */

#endif /* NetworkManager_hpp */
