//
//  CPComboBox.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-05.
//

import AppKit

class CPComboBox: NSView, CanvasProperty {

	var displayHeight: Float = 27.0;

	@IBOutlet weak var label: NSTextField!

	@IBOutlet weak var field: NSComboBox!

	weak var delegate: CPDelegate?

	var items = [String]()

	static func make(label aLabel: String, values: [String], delegate aDelegate: CPDelegate?) -> CPComboBox {
		let view: CPComboBox = NSNib.make(fromNib: "CanvasPropertiesViews", owner: nil);
		view.label.stringValue = aLabel
		view.items = values;
		view.delegate = aDelegate;

		return view;
	}

	@IBAction func comboBoxValueDidChange(_ sender: Any) {
		delegate?.property(label.stringValue, didUpdate: field.stringValue);
	}
}

extension CPComboBox: NSComboBoxDataSource {
	func numberOfItems(in: NSComboBox) -> Int {
		return items.count;
	}

	func comboBox(_ comboBox: NSComboBox, objectValueForItemAt index: Int) -> Any? {
		return items[index];
	}
}
