//
//  EventsDelegate.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-29.
//

import Foundation

protocol EventsDelegate: AnyObject {
	func onEvent(_: String)
}
