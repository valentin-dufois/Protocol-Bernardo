//
//  Core.hpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef Core_hpp
#define Core_hpp

#include <set>

#include "../PoseEstimationEngine/PoseEstimationEngine.hpp"

namespace pb {
namespace tracker {

class TrackerServer;

/// The Core class holds the initialization of the app and the main run loop.
/// This should be one of the first thing created and called on the `main()`
class Core {
public:

	/// Provides a reference to the unique instance of the singleton
	static inline Core * instance() {
		if(_instance == nullptr)
			_instance = new Core();

		return _instance;
	}

	/// Perform initializing tasks run only at the start of the app
	void init();

	/// Main loop of the app
	void run();

	/// Performs proper closing of application components by
	/// deleting the singleton instance
	void terminate();

	/// Properly ends the application
	~Core();

private:

	/// Private constructor
	Core() = default;

	/// Holds the singleton instance
	static Core * _instance;

	// MARK: - Network

	/// The tracker server
	TrackerServer * _server;

	// MARK: - Acquisition

	/// The pose estimation engine
	PoseEstimationEngine _poseEngine;

	/// Called by the Pose Engine  everytime a new body has been received
	/// @param rawBodies A set of rawBodies
	void onRawBodies(const std::set<pb::RawBody *, pb::RawBodyComparator> &rawBodies);
};

} /* ::tracker */
} /* ::pb */

#endif /* Core_hpp */
