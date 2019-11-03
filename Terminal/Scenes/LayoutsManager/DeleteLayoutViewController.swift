//
//  DeleteLayoutViewController.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-30.
//

import AppKit

class DeleteLayoutViewController: NSViewController {

	var layoutName: String!

	@IBOutlet weak var cancelButton: NSButton!
	@IBOutlet weak var deleteButton: NSButton!

	@IBOutlet weak var progressIndicator: NSProgressIndicator!

	@IBAction func onCancel(_ sender: Any) {
		dismiss(sender)
	}

	@IBAction func onDelete(_ sender: Any) {
		// Lock interface
		cancelButton.isEnabled = false;
		deleteButton.isEnabled = false;

		progressIndicator.startAnimation(sender);

		Log.info("Removing layout \(layoutName!)...")
		App.networkEngine.master.deleteLayout(withName: layoutName)
	}
}
