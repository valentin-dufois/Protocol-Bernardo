//
//  CPSection.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import AppKit

class CPSection: NSView, CanvasParameter {
	var displayHeight: Float = 16
	
	@IBOutlet weak var title: NSTextField!

	static func make(title aTitle: String) -> CPSection {
		let view:CPSection = NSNib.make(fromNib: "CanvasParametersViews", owner: nil);
		view.title.stringValue = aTitle;
	
		return view;
	}
}
