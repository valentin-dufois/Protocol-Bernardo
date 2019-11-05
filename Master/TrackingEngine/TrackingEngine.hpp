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

#define TRACKING_ENGINE_RUN_SPEED 30.0 // Times per seconds
#define TRACKING_ENGINE_MERGE_DISTANCE 150.0 // mm
#define TRACKING_ENGINE_BODY_HISTORY_SIZE 1

// MARK: Forward declarations
class RawBody;
class Body;
class LayoutEngine;

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

	// MARK: Bodies accessors

	/// Gives the matching body for the given rawBody if it exists
	/// @param rawbody The rawbody to use
	Body * getBodyFor(const RawBody * rawbody);

	/// Gives a tuple with the closest body from the given rawBody and the distance
	/// in mm between the two. If no bodies are available, the returned body will be
	/// `nullptr`
	///
	/// The coordinates of the given rawBody are converted to the glabel space for
	/// the calculation, the device from which it is coming needs to be associated
	/// with a layout device for this method to work.
	/// @param rawBody The rawbody to use
	std::pair<Body *, SCALAR> getClosestBodyFrom(const RawBody * rawBody);

private:

	// MARK: - Properties

	// Reference to the layout engine
	LayoutEngine * _layoutEngine;

	/// Tell if the engine is active or not
	std::atomic<bool> _isTracking = false;

	/// List all the active captation devices UID sending bodies
	std::vector<std::string> _devicesUID;

	/// All the bodies received since the last cycle
	std::vector<RawBody *> _bodiesBuffer;

	std::vector<Body *> _bodies;

	// MARK: - Private mecanisms

	/// The run loop handling the tracking engines cycles
	void runLoop();

	/// Parse the raw bodies buffer, prefill the bodies and clear the rawbodies
	/// buffer. `parseBodies` locks the _bodiesBuffer while running
	void parseBodies();

	/// Used by the runLoop to cadence its running to the specified cadence
	void cadenceLoop(const std::chrono::duration<double, std::milli> &workTime);

	/// Remove the reference to a rawbody from bodies. If the bodies has ne more
	/// reference after that, it is also removed
	void removeRawBodyReference(const RawBody * rawbody);

	// MARK: System

	std::thread * _executionThread = nullptr;

	std::mutex _bodiesBufferMutex;
};

#endif /* TrackingEngine_hpp */
