//
//  Core.hpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef Core_hpp
#define Core_hpp

#include <set>
#include "../../Common/Network.hpp"

#include "../PoseEstimationEngine/PoseEstimationEngine.hpp"
#include "TrackerInterface.hpp"

namespace pb {
namespace tracker {

/// The Core class holds the initialization of the app and the main run loop.
/// This should be one of the first thing created and called on the `main()`
class Core: public network::SocketDelegate {
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

	// MARK: - SocketDelegate

	virtual void socketDidOpen(network::Socket *) override;

	virtual void socketDidClose(network::Socket *) override;

private:

	/// Private constructor
	Core() = default;

	/// Holds the singleton instance
	static Core * _instance;

	// MARK: - Network

	/// The master browser
	network::Browser _browser;

	/// The socket used to connect to the master
	network::
	Socket _socket;

	// MARK: - Acquisition

	/// The pose estimation engine
	PoseEstimationEngine _poseEngine;

	/// Called by the Pose Engine  everytime a new body has been received
	/// @param rawBodies A set of rawBodies
	void onRawBodies(const std::set<pb::RawBody *, pb::RawBodyComparator> &rawBodies);

	// MARK: - Interface
	TrackerInterface _interface;

};

} /* ::tracker */
} /* ::pb */

#endif /* Core_hpp */
