//
//  Layout.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-30.
//

import Foundation

// Class not struct because we need pass-by-reference
class Layout {
	var name: String = ""

	var devices = [Device]()

	/// Fill in the layout with the given message
	/// - Parameter message: -
	convenience init(fromMessage message: Pb_Network_Messages_Layout) {
		self.init()

		name = message.name

		devices = message.devices.map { Device(fromMessage: $0) }
	}

	func asMessage() -> Pb_Network_Messages_Layout {
		var message = Pb_Network_Messages_Layout()
		message.name = name
		message.devices = devices.map { $0.asMessage() }

		return message
	}
}
