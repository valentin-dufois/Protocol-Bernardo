//
//  TrackingEngineDelegate.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2020-01-26.
//

#ifndef TrackingEngineDelegate_h
#define TrackingEngineDelegate_h

namespace pb {
namespace master {

class TrackingEngineDelegate {
public:
	/// Called everytime the TrackingEngine has updated a body
	virtual void trackingEngineUpdatedBody(TrackingEngine *, Body *) = 0;

	/// Called everytime the TrackingEngine has finished a cycle
	virtual void trackingEngineFinishedCycle(TrackingEngine *) = 0;
};

} /* ::master */
} /* ::pb */

#endif /* TrackingEngineDelegate_h */
