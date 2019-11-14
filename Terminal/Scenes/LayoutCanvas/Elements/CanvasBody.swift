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

	/// The name tag for the device on the scene
	private var xLabel: SKLabelNode!

	/// The name tag for the device on the scene
	private var yLabel: SKLabelNode!

	convenience init(forBody body: Messages_Body) {
		self.init(circleOfRadius: 15);
		alpha = 1.0
		fillColor = NSColor(NSColor.systemPink, alpha: 0.5)
		strokeColor = NSColor(NSColor.systemPink, alpha: 0.8)

		position.x = CGFloat(body.skeletons.last!.centerOfMass.x / 10.0) - 15;
		position.y = CGFloat(body.skeletons.last!.centerOfMass.z / 10.0) + 15;

		xLabel = SKLabelNode(text: "\(body.skeletons.last!.centerOfMass.x/10)")
		xLabel.horizontalAlignmentMode = .center
		xLabel.verticalAlignmentMode = .center
		xLabel.position.y += 15
		xLabel.fontSize = 18
		xLabel.fontName = NSFont.systemFont(ofSize: 11, weight: .bold).fontName

		yLabel = SKLabelNode(text: "\(body.skeletons.last!.centerOfMass.z/10)")
		yLabel.horizontalAlignmentMode = .center
		yLabel.verticalAlignmentMode = .center
		yLabel.position.y -= 15
		yLabel.fontSize = 18
		yLabel.fontName = NSFont.systemFont(ofSize: 11, weight: .bold).fontName

//		self.addChild(xLabel);
//		self.addChild(yLabel);
	}
}
