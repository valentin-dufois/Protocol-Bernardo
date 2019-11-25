//
//  CPValue.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-24.
//

import AppKit

class CPValue: NSView, CanvasProperty {
	var displayHeight: Float = 39

	@IBOutlet weak var label: NSTextField!
	@IBOutlet weak var field: NSTextField!

	static func make(label: String, value: String) -> CPValue {
		let view:CPValue = NSNib.make(fromNib: "CanvasPropertiesViews", owner: nil);
		view.label.stringValue = label;
		view.field.stringValue = value;

		return view;
	}

	func set(value: String) {
		field.stringValue = value;
	}
}
