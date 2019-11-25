
//
//  LayoutEngine.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-30.
//

import Foundation
import SwiftProtobuf

class LayoutEngine {

	private(set) var layout: Layout!

	func setLayout(_ layoutMessage: Pb_Network_Messages_Layout) {
		// Close any open layout if needed

		// Convert the layout message to a more convenient format
		layout = Layout(fromMessage: layoutMessage)

		for device in layout.devices {
			App.mainWindow?.layoutInterface(insertDevice: device)
		}

		// Display the layout interface
		App.mainWindow!.showLayoutInterface()
	}

	func createNewDevice() {
		let device = Device();
		layout.devices.append(device);

		App.mainWindow?.layoutInterface(insertDevice: device)

		Log.info("Added a new device")
	}

	func duplicate(device aDevice: Device) {
		let device = Device(copying: aDevice);

		layout.devices.append(device);
		App.mainWindow?.layoutInterface(insertDevice: device)

		Log.info("Device '\(aDevice.name)' has been duplicated")
	}

	func remove(device aDevice: Device) {
		layout.devices.removeAll { $0.uid == aDevice.uid }

		Log.info("Device '\(aDevice.name)' has been removed from the layout")
	}

	func save() {
		// Check if there is a layout open
		guard layout != nil else {
			return;
		}

		App.networkEngine.master.updateLayout(updatedLayout: layout)
	}
}
