//
//  LayoutInterfaceViewController.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-30.
//

import AppKit
import SpriteKit

class LayoutCanvasViewController: NSViewController {
	var canvas: LayoutCanvasView {
		return view as! LayoutCanvasView
	}

	var parametersView: CanvasPropertiesViewController!

	@IBOutlet weak var parametersLeadingConstraint: NSLayoutConstraint!

	override func viewDidLoad() {
		super.viewDidAppear()

		canvas.controller = self

		NotificationCenter.default.addObserver(self, selector: #selector(resetViewport), name: NSNotification.Name("layoutCanvasResetViewport"), object: nil)

		// Set up the scene
		canvas.allowsTransparency = true
		canvas.presentScene(SKScene(fileNamed: "LayoutCanvasScene"));
		canvas.scene?.delegate = self
	}

	override func prepare(for segue: NSStoryboardSegue, sender: Any?) {
		if segue.identifier == "canvasParametersSegue" {
			parametersView = segue.destinationController as? CanvasPropertiesViewController
			parametersView.viewLeadingConstraint = parametersLeadingConstraint
		}
	}

	func
		showTrackedBodies(_ trackedBodies: Pb_Network_Messages_TrackedBodies) {
		canvas.show(trackedBodies: trackedBodies)

		if(trackedBodies.hasCalibrationValues) {
			canvas.update(calibrationValues: trackedBodies.calibrationValues)
		}
	}

	func clear() {
		canvas.elementsNode.removeAllChildren();
	}
}

// MARK: - User events
extension LayoutCanvasViewController {
	@objc func resetViewport(_: NSNotification) {
		canvas.resetViewport()
	}

	@objc func onNewDevice() {
		App.layoutEngine.createNewDevice();
	}
}

// MARK: - SKSceneDelegate
extension LayoutCanvasViewController: SKSceneDelegate {
	// Insert the given device in the scene
	func insert(device: Device) {
		// Build the new device
		let deviceElement = CanvasDevice(for: device)

		deviceElement.delegate = self;
		canvas.elementsNode.addChild(deviceElement)
		canvas.set(selectedElement: deviceElement)
	}
}

extension LayoutCanvasViewController: CanvasElementDelegate {
	func getDevicesList() -> [CanvasDevice] {
		var devices = [CanvasDevice]();

		canvas.elementsNode.children.forEach {
			guard let device = $0 as? CanvasDevice else {
				return
			}

			devices.append(device);
		}

		return devices
	}

	func device(_ device: CanvasDevice, referenceDidSet reference: String) {
		let referenceDevice = canvas.elementsNode.children.first(where: {
			guard let device = $0 as? CanvasDevice else {
			return false
			}
			return device.device.name == reference;
		}) as! CanvasDevice;

		App.networkEngine.master.setCalibrationDevices(device.device.uid, referenceDevice.device.uid);
	}

	func deselect(_ device: CanvasDevice) {
		canvas.set(selectedElement: nil);
	}
}
