//
//  Log.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-17.
//

import Foundation

class Log {
	enum Level: Int {
		case debug = 1
		case info = 2
		case warning = 3
		case error = 4
		case none = 5
	}

	static var level: Level = .debug;

	static func debug(_ log: Any, _ file: String = #file, _ line: Int = #line) {
		if Log.level.rawValue <= 1 {
			raw("➡️ \(Log.locat(file, line))\(log)");
			App.post(event: "\(log)");
		}
	}

	static func info(_ log: Any, _ file: String = #file, _ line: Int = #line) {
		if Log.level.rawValue <= 1 {
			raw("📢 \(Log.locat(file, line))\(log)");
			App.post(event: "\(log)");
		}
	}

	static func warning(_ log: Any, _ file: String = #file, _ line: Int = #line) {
		if Log.level.rawValue <= 1 {
			raw("⚠️ \(Log.locat(file, line))\(log)");
			App.post(event: "⚠️ \(log)");
		}
	}

	static func error(_ log: Any, _ file: String = #file, _ line: Int = #line) {
		if Log.level.rawValue <= 1 {
			raw("❌ \(Log.locat(file, line))\(log)");
			App.post(event: "❌ \(log)");
		}
	}

	static func raw(_ log: Any) {
		print(log);
	}

	static func locat(_ file: String, _ line: Int) -> String {
		if Log.level.rawValue < 4 {
			return " "
		}

		return " [\(file):\(line)] "
	}
}
