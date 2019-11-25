//
//  CanvasElementDelegate.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-02.
//

import Foundation
import SpriteKit


protocol CanvasElementDelegate: AnyObject {
	func getDevicesList() -> [CanvasDevice];

	func device(_ device: CanvasDevice, referenceDidSet reference: String);

	func deselect(_ device: CanvasDevice);
}
