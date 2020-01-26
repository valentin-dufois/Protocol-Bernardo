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
#include "../TrackingEngine/TrackingEngineDelegate.hpp"

#include "../../Common/Network.hpp"

namespace pb {
struct RawBody;

namespace master {

class Core: public TrackingEngineDelegate {
public:
	void init();

	void run();
private:

	bool _isRunning = true;

	NetworkManager _networkManager;

	LayoutEngine _layoutEngine;

	TrackingEngine _trackingEngine;

	// MARK: TrackingEngineDelegate

	void trackingEngineUpdatedBody(TrackingEngine *, Body *);

	void trackingEngineFinishedCycle(TrackingEngine *);

	std::vector<messages::PartialBody *> _partialBodies;
};

} /* ::master */
} /* ::pb */

#endif /* Core_hpp */
