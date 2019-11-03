//
//  CPDelegate.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import Foundation

protocol CPDelegate: AnyObject {
	func property(_: String, didUpdate newValue: String)

	func property(_: String, didUpdate newValue: Double)
}

// MARK: Optionals
extension CPDelegate {
	func property(_: String, didUpdate newValue: String) {}

	func property(_: String, didUpdate newValue: Double) {}
}
