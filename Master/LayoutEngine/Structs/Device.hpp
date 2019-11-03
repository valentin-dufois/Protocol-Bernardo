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
#include "../../../Common/Messages/messages.hpp"

namespace layout {

struct Device {
	// MARK: - Properties

	/// The name of the device
	std::string name = "Device";

	/// The UID of the device this device correcponds to. If null, it means this layout device corresponds to no physical device.
	std::string uid = "";

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

	Device(const messages::Device & message) {
		name = message.name();
		uid = message.uid();
		horizontalFOV = message.horizontalfov();
		minDistance = message.mindistance();
		maxDistance = message.maxdistance();
		position = maths::fromMessage(message.position());
		orientation = maths::fromMessage(message.orientation());
	}


	operator messages::Device () const {
		messages::Device message;
		message.set_name(name);
		message.set_uid(uid);
		message.set_horizontalfov(horizontalFOV);
		message.set_mindistance(minDistance);
		message.set_maxdistance(maxDistance);
		message.set_allocated_position(maths::asMessage(position));
		message.set_allocated_orientation(maths::asMessage(orientation));

		return message;
	}
};
}

#endif /* Device_h */
