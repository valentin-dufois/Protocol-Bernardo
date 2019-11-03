//
//  CPSection.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import AppKit

class CPSection: NSView, CanvasProperty {
	var displayHeight: Float = 16
	
	@IBOutlet weak var title: NSTextField!

	static func make(title aTitle: String) -> CPSection {
		let view:CPSection = NSNib.make(fromNib: "CanvasPropertiesViews", owner: nil);
		view.title.stringValue = aTitle;
	
		return view;
	}
}
