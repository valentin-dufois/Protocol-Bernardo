//
//  CalibrationValues.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-24.
//

import Foundation
import simd

struct CalibrationValues {
	var angle: simd_double3;
	var position: simd_double3;

	init(fromMessage message: Pb_Network_Messages_CalibrationValues) {
		angle = simd_double3(message.angle.x, message.angle.y, message.angle.z);
		position = simd_double3(message.position.x, message.position.y, message.position.z);
	}
}
