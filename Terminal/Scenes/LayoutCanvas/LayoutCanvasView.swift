//
//  LayoutCanvasView.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-02.
//

import AppKit
import SpriteKit


/// The Layout Canvas View handles the display of the layout in a user friendly way.
///
/// Actions from are handled as much as possible in the view. Actions that changes the structure of the layout, such as adding or removing an element, are passed on to the controller
class LayoutCanvasView: SKView {

	/// The view controller
	weak var controller: LayoutCanvasViewController!

	/// The root node of the scene
	weak var rootNode: SKNode! { return scene?.childNode(withName: "Root") }

	/// The node holding all the layout elements
	weak var elementsNode: SKNode! { return rootNode?.childNode(withName: "Elements") }

	weak var trackedBodiesNode: SKNode! { return rootNode?.childNode(withName: "TrackedBodies") }

	weak var selectedElement: CanvasElement?

	func set(selectedElement element: CanvasElement?) {
		// Make sure to deselect any previously selected element
		selectedElement?.set(appearance: .idle)

		// Update the selected element
		selectedElement = element;
		selectedElement?.set(appearance: .selected)

		guard selectedElement != nil else {
			// Hide the parameters
			controller.parametersView.hideParameters()
			return
		}

		// Display the element parameters
		controller.parametersView.showParameters(selectedElement!.getParametersViews())
	}

	func show(trackedBodies: Messages_TrackedBodies) {
		trackedBodiesNode?.removeAllChildren();

		trackedBodies.bodies.forEach { body in
			trackedBodiesNode?.addChild(CanvasBody(forBody: body));
		}
	}
}

// MARK: - User events
extension LayoutCanvasView {

	/// Uses the given event to update the selected element
	/// - Parameter event: A user event
	func hitTest(forEvent event: NSEvent) {
		for node in elementsNode.children.reversed() {
			guard let element = node as? CanvasElement else {
				continue
			}

			if element.hit(forEvent: event) {
				set(selectedElement: element);
				return;
			}
		}

		// If we are here, it means the user clicked on nothing, deselect the selected element
		set(selectedElement: nil)
	}

	override func mouseDown(with event: NSEvent) {
		super.mouseDown(with: event)

		hitTest(forEvent: event)

		if event.clickCount == 2 {
			openContextualMenu(usingEvent: event)
		}
	}

	override func rightMouseDown(with event: NSEvent) {
		super.rightMouseDown(with: event);

		hitTest(forEvent: event)

		openContextualMenu(usingEvent: event)
	}

	override func scrollWheel(with event: NSEvent) {
		rootNode.position.x = (rootNode.position.x + event.scrollingDeltaX).clamped(to: -1000...1000);
		rootNode.position.y = (rootNode.position.y - event.scrollingDeltaY).clamped(to: -1000...1000);
	}

	override func magnify(with event: NSEvent) {
		// Scale the scene
		let scale = (rootNode.xScale + event.magnification).clamped(to: 0.35...1.25)
		rootNode.xScale = scale
		rootNode.yScale = scale
	}

	override func mouseDragged(with event: NSEvent) {
		selectedElement?.mouseDragged(with: event, forScale: rootNode.xScale)
	}

	override func keyDown(with event: NSEvent) {
		// Check for scene-wide behaviours
		// TODO
		
		// Pass along to selected element
		selectedElement?.onKeyDown(with: event)
	}
}

extension LayoutCanvasView {
	func resetViewport() {
		rootNode.position.x = 0;
		rootNode.position.y = 0;
		rootNode.xScale = 1.0;
		rootNode.yScale = 1.0;
	}
}

// MARK: - Contextual Menu (CM)
extension LayoutCanvasView {
	func openContextualMenu(usingEvent event: NSEvent) {
		let menu = NSMenu(title: "Layout Contextual Menu")

		if selectedElement?.hit(forEvent: event) ?? false {
			selectedElement?.insertContextualMenu(onMenu: menu)
		}

		insertContextualMenu(onMenu: menu)

		NSMenu.popUpContextMenu(menu, with: event, for: self);
	}

	func insertContextualMenu(onMenu menu: NSMenu) {
		if menu.items.count > 0 {
			menu.addItem(NSMenuItem.separator())
		}

		let insertLabel = NSMenuItem(title: "Insert", action: nil, keyEquivalent: "")
		insertLabel.isEnabled = false

		let addDeviceItem = NSMenuItem(title: "Device", action: #selector(controller.onNewDevice), keyEquivalent: "")

		menu.addItem(insertLabel)
		menu.addItem(addDeviceItem)
	}
}
