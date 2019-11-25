//
//  Device.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-30.
//

import Foundation
import simd
import SwiftProtobuf

class Device {
	/// The device's name
	var name: String = "Device"

	/// Unique ID for this device
	private(set) var uid: String! = UUID().uuidString

	/// The device horizontal FOV
	var horizontalFOV: Double = 70.0

	/// The device's minimum captation distance
	var minDistance: Double = 50.0

	/// The device's maximum captation distance
	var maxDistance: Double = 450.0

	/// The device's position (in cm)
	var position = simd_double3(0, 0, 0)

	/// The device's orientation (in degrees)
	var orientation = simd_double3(0, 0, 0)

	var physicalUID: String = ""

	var positionDelta = simd_double3(0, 0, 0);

	var orientationDelta = simd_double3(0, 0, 0);

	/// Fill in the device using the given message
	/// - Parameter message: -
	convenience init(fromMessage message: Pb_Network_Messages_Device) {
		self.init()

		name = message.name
		uid = message.uid
		horizontalFOV = message.horizontalFov
		minDistance = message.minDistance
		maxDistance = message.maxDistance
		position = simd_double3(message.position.x, message.position.y, message.position.z)
		orientation = simd_double3(message.orientation.x, message.orientation.y, message.orientation.z)
		physicalUID = message.physicaluid;
	}

	convenience init(copying device: Device) {
		self.init()

		name = device.name
		horizontalFOV = device.horizontalFOV
		minDistance = device.minDistance
		maxDistance = device.maxDistance
		position = simd_double3(device.position.x + 25, device.position.y + 25, device.position.z)
		orientation = simd_double3(device.orientation.x, device.orientation.y, device.orientation.z)
		physicalUID = device.physicalUID;
	}

	func asMessage() -> Pb_Network_Messages_Device {
		var message = Pb_Network_Messages_Device()
		message.name = name;
		message.uid = uid;
		message.horizontalFov = horizontalFOV;
		message.minDistance = minDistance;
		message.maxDistance = maxDistance;

		var positionMessage = Pb_Network_Messages_vec3()
		positionMessage.x = position.x
		positionMessage.y = position.y
		positionMessage.z = position.z

		var orientationMessage = Pb_Network_Messages_vec3()
		orientationMessage.x = orientation.x
		orientationMessage.y = orientation.y
		orientationMessage.z = orientation.z

		message.position = positionMessage
		message.orientation = orientationMessage

		message.physicaluid = physicalUID

		var positionDeltaMessage = Pb_Network_Messages_vec3()
		positionDeltaMessage.x = positionDelta.x
		positionDeltaMessage.y = positionDelta.y
		positionDeltaMessage.z = positionDelta.z

		var orientationDeltaMessage = Pb_Network_Messages_vec3()
		orientationDeltaMessage.x = orientationDelta.x
		orientationDeltaMessage.y = orientationDelta.y
		orientationDeltaMessage.z = orientationDelta.z

		message.positionDelta = positionDeltaMessage
		message.orientationDelta = orientationDeltaMessage

		return message
	}
}
