//
//  PoseEstimationEngine.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef PoseEstimationEngine_hpp
#define PoseEstimationEngine_hpp

#include <vector>
#include <map>

#include "../libraries.hpp"

#include "Trackers/Tracker.hpp"
#include "Parsers/Parser.hpp"
#include "Devices/Device.hpp"

/// The pose estimation engine handles all the operations necessary to use and control
/// acquisition devices connected to this machine.
///
/// @note For simplicity of use, and because communication with the devices isn't very stable, the engine doesn't allow for direct control of the devices.
///
/// The behaviour of the endgine is as follow:
/// 1. On `start()` the device parsers are started and scout for connected acquisition
/// devices.
/// 2. Upon finding a device, the parser opens a connection, and open a connection
/// with it.
/// 3. The parser notifies the engine of the new device, which creates a Tracker with it.
/// 4. The tracker handles the pose estimation mechanisms and pass along every detected bodies.
///
/// Bodies of the same ID are about the same person on the same device.
class PoseEstimationEngine {
public:

	/// Starts the Pose Estimation Engine operations
	void start();

	/// Called everytime a body is received from a connected device
	std::function<void(const Body * body)> onBody;

private:

	/// Internal method handling newly connected devices
	void onNewDevice(const Device * device);

	/// Holds all the active parsers
	std::vector<Parser *> _parsers;

	/// Holds all the active trackers
	std::vector<Tracker *> _trackers;


};

#endif /* PoseEstimationEngine_hpp */
