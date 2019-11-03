//
//  CPSeparator.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import AppKit

class CPSeparator: NSView, CanvasParameter {
	var displayHeight: Float = 7

	static func make() -> CPSeparator {
		let view:CPSeparator = NSNib.make(fromNib: "CanvasParametersViews", owner: nil);

		return view;
	}
}
