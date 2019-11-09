//
//  CPDouble.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import AppKit

class CPDouble: NSView, CanvasProperty {
	var displayHeight: Float = 25
	
	@IBOutlet weak var label: NSTextField!
	@IBOutlet weak var field: NSTextField!
	@IBOutlet weak var stepper: NSStepper!
	@IBOutlet weak var unit: NSTextField!

	weak var delegate: CPDelegate?

	static func make(label aLabel: String, unit aUnit: String, defaultValue: Double, delegate aDelegate: CPDelegate?) -> CPDouble {
		let view:CPDouble = NSNib.make(fromNib: "CanvasPropertiesViews", owner: nil);
		view.label.stringValue = aLabel;
		view.unit.stringValue = aUnit;

		view.set(value: defaultValue);

		view.delegate = aDelegate

		return view;
	}

	func set(value: Double) {
		stepper.doubleValue = value;
		field.doubleValue = stepper.doubleValue;

		sendUpdate()
	}

	@IBAction func fieldValueDidChange(_ sender: Any) {
		set(value: field.doubleValue)
	}

	@IBAction func stepperValueDidChange(_ sender: Any) {
		field.doubleValue = stepper.doubleValue

		sendUpdate();
	}

	func sendUpdate() {
		delegate?.property(label.stringValue, didUpdate: stepper.doubleValue)
	}
}
