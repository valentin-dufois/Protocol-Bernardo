//
//  Device.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Device_h
#define Device_h

#include <string>
#include "../../../Common/Utils/maths.hpp"

namespace layout {

struct Device {
	// MARK: - Properties

	/// The name of the device
	std::string name = "Device";

	/// The UID of the device this device correcponds to. If null, it means this layout device corresponds to no physical device.
	std::string uid = NULL;

	/// The horizontal FOV of the device.
	/// This is used for representations on the layout but does not affect any calculations
	SCALAR horizontalFOV;

	/// The minimum captation distance of the device
	/// This is used for representations on the layout but does not affect any calculations
	SCALAR minDistance;

	/// The maximum captation distance of the device
	/// This is used for representations on the layout but does not affect any calculations
	SCALAR maxDistance;

	/// The position of the device. This is used for calculations
	vec3 position = vec3(0, 0, 0);

	/// The orientation of the device. This is used for calculations
	vec3 orientation = vec3(0, 0, 0);

	// MARK: - Constructors and Factories

	/// Default constructor
	Device() = default;

	/// Shortcut to build a device representing a kinect
	inline static Device KinectV2() {
		Device d;
		d.name = "Kinect V2";
		d.horizontalFOV = 70.0;
		d.minDistance = 50.0;
		d.maxDistance = 450.0;
		return d;
	}
};
}

#endif /* Device_h */
