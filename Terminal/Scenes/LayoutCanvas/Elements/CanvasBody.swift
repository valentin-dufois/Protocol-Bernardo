//
//  CanvasBody.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-11.
//

import AppKit
import SpriteKit
import SwiftProtobuf

class CanvasBody: SKShapeNode {
	convenience init(forBody body: Messages_Body) {
		self.init(circleOfRadius: 15);
		alpha = 1.0
		fillColor = NSColor(NSColor.systemPink, alpha: 0.5)
		strokeColor = NSColor(NSColor.systemPink, alpha: 0.8)

		position.x = CGFloat(body.skeletons.last!.centerOfMass.x / 10.0);
		position.y = CGFloat(body.skeletons.last!.centerOfMass.z / 10.0);
	}
}
