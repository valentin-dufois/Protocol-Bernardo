//
//  CPComboBox.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-05.
//

import AppKit

class CPPopUp: NSView, CanvasProperty {

	var displayHeight: Float = 27.0;

	@IBOutlet weak var label: NSTextField!

	@IBOutlet weak var field: NSPopUpButton!

	weak var delegate: CPDelegate?

	var items = [String]()

	static func make(label: String, values: [String], delegate: CPDelegate?) -> CPPopUp {
		let view: CPPopUp = NSNib.make(fromNib: "CanvasPropertiesViews", owner: nil);
		view.label.stringValue = label
		view.field.removeAllItems();
		view.field.addItems(withTitles: values);
		view.delegate = delegate;

		return view;
	}

	@IBAction func popUpButtonValueDidChange(_ sender: Any) {
		delegate?.property(label.stringValue, didUpdate: field.titleOfSelectedItem!);
	}
}
