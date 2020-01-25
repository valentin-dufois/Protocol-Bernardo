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
			device.position.x = Double(position.x)
			device.position.y = Double(position.y)

			positionParameters?.set(XValue: device.position.x, sendUpdate: false)
			positionParameters?.set(YValue: device.position.y, sendUpdate: false)
		}
	}

	var positionParameters: CPXY?

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


	// MARK: - Parameters

	weak var positionXDelta: CPValue?
	weak var positionYDelta: CPValue?
	weak var positionZDelta: CPValue?
	weak var yawDelta: CPValue?
	weak var pitchDelta: CPValue?

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
	func getParametersViews() -> [CanvasProperty] {
		var devicesList = App.masterStatus.connectedDevices;

		if !devicesList.contains(device.physicalUID) {
			devicesList.append(device.physicalUID);
		}

		devicesList.sort()

		var views = [CanvasProperty]()

		// Device name
		views.append(CPSection.make(title: "Device"))
		views.append(CPString.make(label: "Name",
								   defaultValue: device.name,
								   delegate: self))

		// Device placement
		views.append(CPSeparator.make())
		views.append(CPSection.make(title: "Position"))

		positionParameters = CPXY.make(prefix: "pos",
									   defaultX: device.position.x,
									   defaultY: device.position.y,
									   unit: "cm",
									   delegate: self)
		views.append(positionParameters!)

		views.append(CPDouble.make(label: "Yaw",
								   unit: "º",
								   defaultValue: device.orientation.z,
								   delegate: self))
		views.append(CPDouble.make(label: "Pitch",
								   unit: "º",
								   defaultValue: device.orientation.x,
								   delegate: self))
		views.append(CPDouble.make(label: "Height",
								  unit: "cm",
								  defaultValue: device.position.z,
								  delegate: self))

		// Device properties
		views.append(CPSeparator.make())
		views.append(CPSection.make(title: "Captation"))
		views.append(CPDouble.make(label: "Field of View",
								   unit: "º",
								   defaultValue: device.horizontalFOV,
								   delegate: self))
		views.append(CPDouble.make(label: "Min. Dist.",
								   unit: "cm",
								   defaultValue: device.minDistance,
								   delegate: self))
		views.append(CPDouble.make(label: "Max. Dist.",
								   unit: "cm",
								   defaultValue: device.maxDistance,
								   delegate: self))

		// Real-world
		views.append(CPSeparator.make())
		views.append(CPSection.make(title: "Physical Device"))
		let physicalUIDField = CPComboBox.make(label: "UID",
											   values: devicesList,
											   delegate: self)
		physicalUIDField.field.stringValue = device.physicalUID;
		views.append(physicalUIDField);

		// Calibration
		views.append(CPSeparator.make())
		views.append(CPSection.make(title: "Calibration"))

		var devicesNames = delegate?.getDevicesList().map({ $0.device.name }) ?? [];
		devicesNames.insert("", at: 0);
		views.append(CPPopUp.make(label: "Reference", values: devicesNames.filter({ $0 != device.name }), delegate: self));

		positionXDelta = CPValue.make(label: "Position X", value: nil)
		positionYDelta = CPValue.make(label: "Position Y", value: nil)
		positionZDelta = CPValue.make(label: "Position Z", value: nil)
		yawDelta = CPValue.make(label: "Yaw", value: nil)
		pitchDelta = CPValue.make(label: "Pitch", value: nil)

		views.append(positionXDelta!);
		views.append(positionYDelta!);
		views.append(positionZDelta!);
		views.append(yawDelta!);
		views.append(pitchDelta!);

		return views
	}
}

extension CanvasDevice: CPDelegate {
	func property(_ pName: String, didUpdate newValue: Double) {
		switch pName {
		case "posX": position.x = CGFloat(newValue)
		case "posY": position.y = CGFloat(newValue)
		case "Yaw": device.orientation.z = newValue
		case "Pitch": device.orientation.x = newValue
		case "Height": device.position.z = newValue
		case "Field of View": device.horizontalFOV = newValue
		case "Min. Dist.": device.minDistance = newValue
		case "Max. Dist.": device.maxDistance = newValue
		default: return
		}

		refreshAppearance()
	}

	func property(_ pName: String, didUpdate newValue: String) {
		switch pName {
		case "Name": device.name = newValue
		case "UID": device.physicalUID = newValue
		case "Reference": delegate?.device(self, referenceDidSet: newValue)
		default: return
		}

		refreshAppearance()
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

	private func refreshAppearance() {
		deviceLabel.text = device.name

		captationAreaNode.path = captationArea()
		captationAreaNode.zRotation = CGFloat(deg2rad(device.horizontalFOV / -2 + device.orientation.z + 90))
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
		// Remove the associated device from the layout
		App.layoutEngine.remove(device: device)

		delegate?.deselect(self);

		// Remove ourselves from the canvas
		removeFromParent()
	}


	@objc func duplicate() {
		App.layoutEngine.duplicate(device: device)
	}
}
