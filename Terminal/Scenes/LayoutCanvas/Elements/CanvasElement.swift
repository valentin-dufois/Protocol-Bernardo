//
//  CanvasElement.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-02.
//

import AppKit
import SpriteKit

protocol CanvasElement: SKNode {
	// MARK: Properties

	// The delegate, a reference to the canvas
	var delegate: CanvasElementDelegate? { get set }

	/// The element position
	var position: CGPoint { get set }

	/// Tell if the element is interactive and should receive user events
	var isInteractive: Bool { get }


	// MARK: Actions

	/// Updates the appearance of the device
	/// - Parameter appearance: The appearance to use
	func set(appearance: CanvasElementAppearance)

	/// Gives the element parameters view controller
	func getParametersViews() -> [CanvasProperty]

	// MARK: Events

	func mouseDragged(with event: NSEvent, forScale scale: CGFloat)

	func onKeyDown(with event: NSEvent)

	func remove()

	func duplicate()

	// MARK: Misc

	/// Perform a hit test for the given event on the current element
	func hit(forEvent: NSEvent) -> Bool

	func insertContextualMenu(onMenu: NSMenu)
}

// MARK: - Events
extension CanvasElement {
	func mouseDragged(with event: NSEvent, forScale scale: CGFloat) {
		self.position.x += (event.deltaX / scale)
		self.position.y -= (event.deltaY / scale)
	}

	func onKeyDown(with event: NSEvent) {
		switch event.keyCode {
		case Keycode.delete: remove()
		case Keycode.upArrow: translate(withEvent: event)
		case Keycode.downArrow: translate(withEvent: event)
		case Keycode.rightArrow: translate(withEvent: event)
		case Keycode.leftArrow: translate(withEvent: event)
		case Keycode.d:
			if event.modifierFlags.contains(.command) {
				duplicate()
			}
		default: break
		}
	}

	/// Translate the node by the amount specified by the given MouseDragged event
	///
	/// - Parameter event:
	func translate(withEvent event: NSEvent) {
		let translateAmount: CGFloat = event.modifierFlags.contains(.shift) ? 10 : 1

		switch event.keyCode {
		case Keycode.upArrow: position.y += translateAmount
		case Keycode.downArrow: position.y -= translateAmount
		case Keycode.rightArrow: position.x += translateAmount
		case Keycode.leftArrow: position.x -= translateAmount
		default: break
		}
	}
}

// MARK: Utils
extension CanvasElement {
	/// The highlight color is the color to use to tell that this device is selected
	internal var highlightColor: NSColor {
		return NSColor.controlAccentColor
	}
}
