//
//  App.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-28.
//

import AppKit

struct App {

	static var isStarting = true;

	/// Handles communication with the master app
	static let networkEngine = NetworkEngine()

	static weak var eventsDelegate: EventsDelegate?

	static func post(event: String) {
		eventsDelegate?.onEvent(event);
	}

	static weak var mainWindow: MainWindowController?

	static var layoutEngine = LayoutEngine()
}
