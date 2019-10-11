//
//  Core.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef Core_hpp
#define Core_hpp

#include "../../Common/CommunicationEngine/Discovery/Advertiser.hpp"
#include "../PoseEstimationEngine/PoseEstimationEngine.hpp"

class AcquisitorServer;
class Body;

/// The Core class holds the initialization of the app and the main run loop.
/// This should be one of the first thing created and called on the `main()`
class Core {
public:

	/// Perform initializing tasks run only at the start of the app
	void init();

	/// Main loop of the app
	void run();

	/// Properly ends the application
	~Core();

private:

	// MARK: - Communication

	/// The acquisitor server
	AcquisitorServer * _server;

	// MARK: - Acquisition

	/// The pose estimation engine
	PoseEstimationEngine _poseEngine;

	/// Called by the Pose Engine  everytime a new body has been received
	void onBody(const Body * body);
};

#endif /* Core_hpp */
