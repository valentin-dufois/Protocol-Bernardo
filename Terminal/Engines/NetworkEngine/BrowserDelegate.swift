//
//  BrowserDelegate.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-15.
//

import Foundation
import Socket

protocol BrowserDelegate {
	func browser(_: Browser, didFoundMaster: Messages_Endpoint, withIP: String)
}
