//
//  MainWindowContoller.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-15.
//

import AppKit
import SwiftProtobuf

class MainWindowController: NSWindowController {

	@IBOutlet weak var statusBar: NSSegmentedControl!

	@IBOutlet weak var releaseLabel: NSTextField!

	@IBOutlet weak var toolbar: NSToolbar!

	var controller: MainViewController {
		return contentViewController as! MainViewController
	}

	override func windowDidLoad() {
		App.mainWindow = self;
		App.eventsDelegate = self;

		// Set up build label
		let buildNumber: String = Bundle.main.object(forInfoDictionaryKey: "CFBundleVersion") as! String;
		releaseLabel.stringValue = "Development release \(buildNumber)";

		toolbar.centeredItemIdentifier = NSToolbarItem.Identifier(rawValue: "StatusBarItem")

	}

	func showLayoutList(_ list: Messages_LayoutList) {
		closeLayoutList()

		DispatchQueue.main.async {
			self.controller.performSegue(withIdentifier: "layoutListSegue", sender: list);
		}
	}

	func closeLayoutList() {
		DispatchQueue.main.async {
			self.controller.closeLayoutsList()
		}
	}

	func showLayoutInterface() {
		closeLayoutInterface()

		DispatchQueue.main.async {
			self.controller.showLayoutInterface()
		}
	}

	func closeLayoutInterface() {
		DispatchQueue.main.async {
			self.controller.closeLayoutInterface()
		}
	}

	@IBAction func refreshMasterStatus(_ sender: Any) {
		App.networkEngine.requestMasterStatus();
	}

	func showTrackedBodies(_ trackedBodies: Messages_TrackedBodies) {
		DispatchQueue.main.async {
			self.controller.layoutInterfaceController?.showTrackedBodies(trackedBodies)
		}
	}
}

extension MainWindowController: EventsDelegate {
	func onEvent(_ event: String) {
		DispatchQueue.main.async {
			self.statusBar.setLabel(event, forSegment: 0);
		}
	}
}

extension MainWindowController {
	func layoutInterface(insertDevice device: Device) {
		DispatchQueue.main.async {
			self.controller.layoutInterfaceController?.insert(device: device);
		}
	}
}
