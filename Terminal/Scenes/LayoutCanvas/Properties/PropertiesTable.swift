//
//  ParametersTable.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import AppKit

class PropertiesTable: NSTableView {
	override func validateProposedFirstResponder(_ responder: NSResponder, for event: NSEvent?) -> Bool {
		if responder is NSControl {
			return true
		}

		return super.validateProposedFirstResponder(responder, for: event)
	}
}
