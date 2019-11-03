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

	var parametersView: CanvasParametersViewController!

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
			parametersView = segue.destinationController as? CanvasParametersViewController
			parametersView.viewLeadingConstraint = parametersLeadingConstraint
		}
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

		canvas.elementsNode.addChild(deviceElement)
		canvas.set(selectedElement: deviceElement)
	}
}
