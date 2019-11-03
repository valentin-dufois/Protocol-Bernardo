//
//  NewLayoutViewController.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-30.
//

import AppKit

class NewLayoutViewController: NSViewController {

	@IBOutlet weak var layoutNameField: NSTextField!

	@IBOutlet weak var cancelButton: NSButton!

	@IBOutlet weak var createButton: NSButton!
	
	@IBOutlet weak var progressIndicator: NSProgressIndicator!

	@IBAction func onEdit(_ sender: Any) {
		createButton.isEnabled = layoutNameField.stringValue.trimmingCharacters(in: [" "]).count > 3
	}

	@IBAction func onCancel(_ sender: Any) {
		dismiss(sender);
	}

	@IBAction func onCreate(_ sender: Any) {
		// Validate layout name
		let layoutName = layoutNameField.stringValue.trimmingCharacters(in: [" "])

		guard layoutName.count > 3 else {
			return
		}

		// Lock interface
		createButton.isEnabled = false
		cancelButton.isEnabled = false
		layoutNameField.isEnabled = false

		progressIndicator.startAnimation(nil);

		// Create the layout
		Log.info("Creating layout \(layoutName)...")
		App.networkEngine.master.createLayout(withName: layoutName)
	}
}
