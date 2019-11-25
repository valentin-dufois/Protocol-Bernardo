//
//  Device.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Device_h
#define Device_h

#include <string>
#include "../../../Common/common.hpp"
#include "../../../Common/Utils.hpp"
#include "../../../Common/Network/Messages/messages.hpp"

namespace pb {
namespace layout {

struct Device {
	// MARK: - Base properties

	/// The name of the device
	std::string name = "Device";

	/// The unique identifier for this logic device
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
	maths::vec3 position = maths::vec3(0, 0, 0);

	/// The orientation of the device. This is used for calculations
	maths::vec3 orientation = maths::vec3(0, 0, 0);


	// MARK: - Calibration properties

	/// The UID of the physical device this device correcponds to. If null, it means it corresponds to no physical device.
	pb::deviceUID physicalUID = "";

	/// The position difference between the logic device and the physical device
	maths::vec3 positionDelta = maths::vec3(0, 0, 0);

	/// The orientation difference between the logic and physical device
	maths::vec3 orientationDelta = maths::vec3(0, 0, 0);


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

	Device(const network::messages::Device & message) {
		name = message.name();
		uid = message.uid();
		horizontalFOV = message.horizontalfov();
		minDistance = message.mindistance();
		maxDistance = message.maxdistance();
		position = maths::fromMessage(message.position());
		orientation = maths::fromMessage(message.orientation());

		physicalUID = message.physicaluid();
		positionDelta = maths::fromMessage(message.positiondelta());
		orientationDelta = maths::fromMessage(message.orientationdelta());
	}


	operator network::messages::Device () const {
		network::messages::Device message;

		message.set_name(name);
		message.set_uid(uid);
		message.set_horizontalfov(horizontalFOV);
		message.set_mindistance(minDistance);
		message.set_maxdistance(maxDistance);
		message.set_allocated_position(maths::asMessage(position));
		message.set_allocated_orientation(maths::asMessage(orientation));

		message.set_physicaluid(physicalUID);
		message.set_allocated_positiondelta(maths::asMessage(positionDelta));
		message.set_allocated_orientationdelta(maths::asMessage(orientationDelta));

		return message;
	}
};

} /* ::layout */
} /* ::pb */

#endif /* Device_h */
