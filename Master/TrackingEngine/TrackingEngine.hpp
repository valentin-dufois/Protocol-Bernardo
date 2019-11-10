//
//  TrackingEngine.hpp
//  pb-master
//
//  Created by Valentin Dufois on 2019-11-04.
//

#ifndef TrackingEngine_hpp
#define TrackingEngine_hpp

#include <vector>
#include <atomic>
#include <thread>
#include <mutex>

#include "../../Common/common.hpp"
#include "../../Common/Utils/maths.hpp"

// MARK: Forward declarations
class LayoutEngine;
class Skeleton;
class RawBody;
class Body;

// MARK: - Tracking Engine
/// The tracking engine takes Raw Bodies from the tracking devices as input and
/// outputs Bodies aggregated from one or more raw bodies. The tracking engine uses a
/// layout to go from acquisition devices' local space to the global space. Without
/// an active layout, the tracking engine will not work.
///
/// The Tracking engine takes input raw bodies in a best-effort manner, but for technical reasons will output bodies in a cadenced manner specified by `TRACKING_ENGINE_RUN_SPEED`.
class TrackingEngine {
public:

	/// Set the layout engine the Tracking Engine will rely one for calculations
	/// @param layoutEngine The layout engine
	inline void setLayoutEngine(LayoutEngine * layoutEngine) { _layoutEngine = layoutEngine; }

	/// Starts the tracking engine
	void start();

	/// Stops the tracking engine
	inline void stop() { _isTracking = false; };

	/// Call this method to give the TrackingEngine a new rawBody to work with
	/// @param body The body to handle
	void onRawBody(RawBody * body);

	/// This method is called every time the Tracking Engine finishes a cycle.
	std::function<void(std::vector<Body *>)> onCycleEnd;

	inline std::unordered_set<pb::deviceUID> getConnectedDevicesUID() {
		return _devicesUID;
	}

	// MARK: Bodies accessors

	/// Gives the matching body for the given rawBody if it exists
	/// @param rawbody The rawbody to use
	Body * getBodyFor(const RawBody * rawbody);

	/// Gives a list of tuples with a body and the distance from it to the given
	/// target, ordered closest to farthest
	///
	/// The coordinates of the given target must be in the global global space
	/// @param target The rawbody to use
	std::vector<std::pair<Body *, SCALAR>> getClosestBodiesFrom(const Skeleton * target);

	/// Gives a tuple with the closest body from the given Skeleton and the distance
	/// in mm between the two. If no bodies are available, the returned body will be
	/// `nullptr`
	///
	/// The coordinates of the given target must be in the global global space
	/// @param target The rawbody to use
	std::pair<Body *, SCALAR> getClosestBodyFrom(const Skeleton * target);

private:

	// MARK: - Properties

	// Reference to the layout engine
	LayoutEngine * _layoutEngine;

	/// Tell if the engine is active or not
	std::atomic<bool> _isTracking = false;

	/// List all the active captation devices UID sending bodies
	std::unordered_set<pb::deviceUID> _devicesUID;

	/// All the bodies received since the last cycle
	std::vector<RawBody *> _bodiesBuffer;

	/// All the bodies actively tracked by the tracking engine
	std::vector<Body *> _bodies;

	// MARK: - Private mecanisms

	/// The run loop handling the tracking engines cycles
	void runLoop();

	/// Execute all the operations neecessary for tracking properly the bodies
	void trackBodies();

	/// Parse the raw bodies buffer, prefill the bodies and clear the rawbodies
	/// buffer. `parseBodies` locks the _bodiesBuffer while running
	void parseBodiesBuffer();

	/// Execute the updates script on all the users, convrting their local skeletons
	/// to one unique global skeletons. Also update their history
	void updateBodies();

	/// Excute a new, different pass, on all the skeletons to make their is only only
	/// one Body for one human.
	void parseBodies();

	/// Clear the `_bodiesBuffer`
	void clearBuffer();

	/// Used by the runLoop to cadence its running to the specified cadence
	void cadenceLoop(const std::chrono::duration<double, std::milli> &workTime);

	/// Remove the reference to a rawbody from bodies. If the bodies has ne more
	/// reference after that, it is also removed
	void removeRawBodyReference(const RawBody * rawbody);

	// MARK: System

	/// The thread on which the tracking engine run loop is running
	std::thread * _executionThread = nullptr;

	/// Mutex for the bodies buffer as it will be accessed from  multiple threads
	std::mutex _bodiesBufferMutex;
};

#endif /* TrackingEngine_hpp */
