//
//  CanvasDevice.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-02.
//

import AppKit
import SpriteKit

class CanvasDevice: SKNode {
	/// The device this node is representing
	weak var device: Device!

	weak var delegate: CanvasElementDelegate?

	override var position: CGPoint {
		didSet {
			device?.position.x = Double(position.x)
			device?.position.y = Double(position.y)
		}
	}

	/// A device is an interactive element
	var isInteractive = true

	// MARK: - Appearance
	/// The sprite node holding the device image
	private var deviceSprite: SKSpriteNode!

	/// The circle appearing only when selected
	private var centerCircle: SKShapeNode!

	/// The shape representing the device captation area
	private var captationAreaNode: SKShapeNode!

	/// The name tag for the device on the scene
	private var deviceLabel: SKLabelNode!

}

extension CanvasDevice {
	/// Initialize a Device node
	///
	/// - Parameters:
	///   - layoutView: The layoutView on which the node should be inserted
	///   - device: The device the node will represent
	convenience init(for aDevice: Device) {
		self.init()

		// Set the represented device
		self.device = aDevice

		// copy the values from the device to ourselves
		self.name = device.uid
		self.position = CGPoint(x: CGFloat(device.position.x), y: CGFloat(device.position.y))

		// Build the device sprite node
		deviceSprite = SKSpriteNode(imageNamed: "Device")
		deviceSprite.position.y += 5
		deviceSprite.setScale(0.10)
		deviceSprite.colorBlendFactor = 1.0

		deviceLabel = SKLabelNode(text: device.name)
		deviceLabel.horizontalAlignmentMode = .center
		deviceLabel.verticalAlignmentMode = .center
		deviceLabel.position.y -= 8
		deviceLabel.fontSize = 11
		deviceLabel.fontName = NSFont.systemFont(ofSize: 11, weight: .bold).fontName

		centerCircle = SKShapeNode(circleOfRadius: 25)

		// Build the captation area node
		captationAreaNode = SKShapeNode(path: captationArea())
		captationAreaNode.zRotation = CGFloat(deg2rad(device.horizontalFOV / -2 + device.orientation.z + 90))

		// Give them their idle style
		set(appearance: .idle)

		isUserInteractionEnabled = false

		// Insert them in the tree
		self.addChild(centerCircle)
		self.addChild(captationAreaNode)
		self.addChild(deviceSprite)
		self.addChild(deviceLabel)
	}
}

// MARK: - CanvasElement
extension CanvasDevice: CanvasElement {
	func getParametersViewController() -> NSViewController {
		return NSViewController()
	}
}


// MARK: - Appearance
extension CanvasDevice {
	func set(appearance: CanvasElementAppearance) {
		switch appearance {
		case .idle: setIdleAppearance()
		case .selected: setSelectedAppearance()
		}
	}

	/// Set the device appearance to reflect its idle state
	private func setIdleAppearance() {
		deviceSprite.color = NSColor(calibratedWhite: 0, alpha: 0.9)
		deviceLabel.fontColor = NSColor(calibratedWhite: 0, alpha: 0.8)

		centerCircle.alpha = 0.0

		captationAreaNode.fillColor = NSColor(calibratedWhite: 0, alpha: 0.5)
		captationAreaNode.strokeColor = NSColor(calibratedWhite: 0, alpha: 0.8)
	}

	/// Set the device appearance to reflect its selected state
	private func setSelectedAppearance() {
		centerCircle.alpha = 1.0
		centerCircle.fillColor = NSColor(highlightColor, alpha: 0.5)
		centerCircle.strokeColor = NSColor(highlightColor, alpha: 0.8)

		captationAreaNode.fillColor = NSColor(highlightColor, alpha: 0.5)
		captationAreaNode.strokeColor = NSColor(highlightColor, alpha: 0.8)
	}
}

// /////////////////////
// MARK: - SKNode utils
extension CanvasDevice {
	/// Gives the CGPath corresponding to the device captation area
	///
	/// - Returns: A CGPath representing an arc
	private func captationArea() -> CGMutablePath {
		let angle = CGFloat(deg2rad(device.horizontalFOV))

		let path = CGMutablePath()
		path.addArc(center: CGPoint.zero,
					radius: CGFloat(device.minDistance),
					startAngle: angle,
					endAngle: 0,
					clockwise: true)
		path.addLine(to: CGPoint(x: device.maxDistance, y: 0))
		path.addArc(center: CGPoint.zero,
					radius: CGFloat(device.maxDistance),
					startAngle: 0,
					endAngle: angle,
					clockwise: false)
		path.closeSubpath()

		return path
	}

	/// Tell if the cursor described by the given mouse event falls inside the
	/// device trigger areas
	///
	/// - Parameter event: Mouse event
	/// - Returns: True if the cursor is inside the trigger area, false otherwise
	func hit(forEvent event: NSEvent) -> Bool {
		let clickLocationCaptationArea = event.location(in: captationAreaNode)
		let clickLocationCenterArea = event.location(in: centerCircle)

		if captationAreaNode.path!.contains(clickLocationCaptationArea) ||
			centerCircle.contains(clickLocationCenterArea) {
			return true
		}

		return false
	}
}

// MARK: - Contextual Menu (CM)
extension CanvasDevice {
	func insertContextualMenu(onMenu menu: NSMenu) {
		if menu.items.count > 0 {
			menu.addItem(NSMenuItem.separator())
		}

		let deviceLabel = NSMenuItem(title: device.name, action: nil, keyEquivalent: "")
		deviceLabel.isEnabled = false

		let removeDeviceItem = NSMenuItem(title: "Remove", action: #selector(remove), keyEquivalent: String(format: "%c", NSBackspaceCharacter))
		removeDeviceItem.keyEquivalentModifierMask = []
		removeDeviceItem.target = self

		let duplicateDeviceItem = NSMenuItem(title: "Create a copy", action: #selector(duplicate), keyEquivalent: "d")
		duplicateDeviceItem.target = self

		menu.addItem(deviceLabel)
		menu.addItem(removeDeviceItem)
		menu.addItem(duplicateDeviceItem)
	}
}

// MARK: - User Interactions
extension CanvasDevice {
	@objc func remove() {
		let deviceName = device.name;
		// Remove the associated device from the layout
		App.layoutEngine.remove(device: device)

		// Remove ourselves from the canvas
		removeFromParent()
	}


	@objc func duplicate() {
		App.layoutEngine.duplicate(device: device)
	}
}
