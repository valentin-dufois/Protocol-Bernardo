//
//  CPValue.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-24.
//

import AppKit

class CPValue: NSView, CanvasProperty {
	var displayHeight: Float = 39

	@IBOutlet weak var box: NSBox!
	@IBOutlet weak var label: NSTextField!
	@IBOutlet weak var field: NSTextField!

	static func make(label: String, value: Double?) -> CPValue {
		let view:CPValue = NSNib.make(fromNib: "CanvasPropertiesViews", owner: nil);
		view.label.stringValue = label;
		view.field.stringValue = value != nil ? String(value!) : "-";

		return view;
	}

	func set(value: Double?) {
		field.stringValue = value != nil ? String(value!) : "-";

		if(abs(value ?? Double.infinity) < 5) {
			box.borderColor = NSColor.green;
			field.textColor = NSColor.green;
			label.textColor = NSColor.green;
		} else {
			box.borderColor = NSColor.secondaryLabelColor;
			field.textColor = NSColor.labelColor;
			label.textColor = NSColor.labelColor;
		}
	}
}
