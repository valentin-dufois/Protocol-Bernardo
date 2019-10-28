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

#include "../../../Common/Utils/Log.hpp"
#include "../../../Common/CommunicationEngine/CommunicationEngine.hpp"
#include "../../../Common/CommunicationEngine/Discovery/Advertiser.hpp"
#include "../../../Common/CommunicationEngine/Discovery/Browser.hpp"
#include "../../../Common/Messages/messages.hpp"

#include "MasterServer.hpp"

class AcquisitorClient;
class LayoutEngine;

class NetworkManager {
public:

	NetworkManager();

	/// Start all acivities of the network manager
	void startActivities();

	/// Open a connection to the given endpoint. If successful, the corresponding callabacks will be called.
	/// @param endpoint The endpoint to connect to
	void connectTo(const Endpoint &endpoint);

	/// Called everytime a new Acquisitor is connected
	std::function<void(AcquisitorClient *)> onAcquisitor;

	/// Called everytime a new Broadcaster is connected
//	std::function<void()> onBroadcaster;

	/// Called everytime a new Terminal is connected
	std::function<void()> onTerminal;


	inline void setLayoutEngine(LayoutEngine * layoutEngine) {
		_masterServer.layoutEngine = layoutEngine;
	}

private:

	/// Used to find Acquisitors on the network
	Browser _acquisitorBrowser;

	/// Used to find Broadcasters on the network
	Browser _broadcasterBrowser;

	/// The list of endpoints we are connected to
	std::vector<Endpoint> _connectedEndpoints;

	/// Establishes a connection to the given Acquisitor
	void connectToAcquisitor(const Endpoint &endpoint);

	/// Establishes a connection to the given Broadcaster
//	void connectToBroadcaster(const Endpoint &endpoint);

	/// The master server
	MasterServer _masterServer;

};

#endif /* NetworkManager_hpp */
