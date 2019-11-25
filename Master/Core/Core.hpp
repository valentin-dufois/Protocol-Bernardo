//
//  Core.hpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Core_hpp
#define Core_hpp

#include "Network/NetworkManager.hpp"
#include "../LayoutEngine/LayoutEngine.hpp"
#include "../TrackingEngine/TrackingEngine.hpp"

#include "../../Common/Network.hpp"

namespace pb {
struct RawBody;

namespace master {

class Core {
public:
	void init();

	void run();

	void onTracker(TrackerClient * tracker);
private:

	bool _isRunning = true;

	NetworkManager _networkManager;

	LayoutEngine _layoutEngine;

	TrackingEngine _trackingEngine;

	// Events
	void onTrack(const std::map<pb::bodyUID, Body *> &bodies);
};

} /* ::master */
} /* ::pb */

#endif /* Core_hpp */
