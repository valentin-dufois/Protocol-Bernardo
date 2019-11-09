//
//  CanvasParameterXYField.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import AppKit

class CPXY: NSView, CanvasProperty {
	var displayHeight: Float = 42

	@IBOutlet weak var XField: NSTextField!
	@IBOutlet weak var XStepper: NSStepper!

	@IBOutlet weak var YField: NSTextField!
	@IBOutlet weak var YStepper: NSStepper!

	@IBOutlet weak var unit: NSTextField!

	var prefix: String = ""

	weak var delegate: CPDelegate?

	static func make(prefix aPrefix: String, defaultX: Double, defaultY: Double, unit aUnit: String, delegate aDelegate: CPDelegate?) -> CPXY {
		let view:CPXY = NSNib.make(fromNib: "CanvasPropertiesViews", owner: nil);
		view.prefix = aPrefix

		view.set(XValue: defaultX);
		view.set(YValue: defaultY);

		view.unit.stringValue = aUnit;

		view.delegate = aDelegate

		return view;
	}

	func set(XValue value: Double, sendUpdate: Bool = true) {
		XStepper.doubleValue = value;
		XField.doubleValue = XStepper.doubleValue;

		if sendUpdate {
			sendXUpdate()
		}
	}

	func set(YValue value: Double, sendUpdate: Bool = true) {
		YStepper.doubleValue = value;
		YField.doubleValue = YStepper.doubleValue;

		if sendUpdate {
			sendYUpdate()
		}
	}

	@IBAction func XFieldValueDidChange(_ sender: Any) {
		set(XValue: XField.doubleValue)
	}

	@IBAction func YFieldValueDidChange(_ sender: Any) {
		set(YValue: YField.doubleValue)
	}

	@IBAction func XStepperValueDidChange(_ sender: Any) {
		XField.doubleValue = XStepper.doubleValue

		sendXUpdate();
	}

	@IBAction func YStepperValueDidChange(_ sender: Any) {
		YField.doubleValue = YStepper.doubleValue

		sendYUpdate();
	}

	func sendXUpdate() {
		delegate?.property("\(prefix)X", didUpdate: XStepper.doubleValue)
	}

	func sendYUpdate() {
		delegate?.property("\(prefix)Y", didUpdate: YStepper.doubleValue)
	}
}

