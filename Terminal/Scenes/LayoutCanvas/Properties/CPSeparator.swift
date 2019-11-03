//
//  CPSeparator.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import AppKit

class CPSeparator: NSView, CanvasProperty {
	var displayHeight: Float = 7

	static func make() -> CPSeparator {
		let view:CPSeparator = NSNib.make(fromNib: "CanvasPropertiesViews", owner: nil);

		return view;
	}
}
