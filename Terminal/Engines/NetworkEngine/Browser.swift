//
//  Browser.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-15.
//

import Foundation
import Socket

class Browser {

	public var delegate: BrowserDelegate?

	private var _socket: Socket

	private var _isBrowsing: Bool = false

	private var _thread: DispatchQueue

	public init() {
		_socket = try! Socket.create(family: .inet, type: .datagram, proto: .udp)
		_thread = DispatchQueue.global(qos: .utility)
	}

	public func startBrowsing() {
		if _isBrowsing {
			// Already browsing, do nothing
			return
		}

		_isBrowsing = true;

		_thread.async {
			self.receptionLoop()
		}
	}

	public func stopBrowsing() {
		_isBrowsing = false;
	}

	private func receptionLoop() {

		try! _socket.listen(on: 40003);

		while(_isBrowsing) {
			var data = Data()

			// Listen for a datagram
			let (bytesCount, address) = try! _socket.readDatagram(into: &data);

			guard bytesCount >= 0 else {
				print("No data received")
				continue; // No data received
			}

			guard let message = try? Messages_Endpoint(serializedData: Data(data)) else {
				print("Could not decode received object to Endpoint")
				return
			}

			delegate?.browser(self, didFoundMaster: message, withIP: NetworkEngine
				.ip(from: address!));
		}
	}
}
