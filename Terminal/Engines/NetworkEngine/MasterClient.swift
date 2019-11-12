//
//  MasterClient.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-17.
//

import Foundation
import Socket
import SwiftProtobuf

class MasterClient {

	var delegate: MasterClientDelegate?;

	private var _socket: Socket;

	private var _thread = DispatchQueue.global(qos: .userInitiated);

	private(set) var remoteIP: String!;

	private(set) var isOpen: Bool = false;

	// Create the client, connecting it to the given IP
	init() {
		_socket = try! Socket.create(family: .inet, type: .stream, proto: .tcp);
	}

	public func open(to ip: String) {
		remoteIP = ip;
		
		guard !isOpen else {
			return; // Connection already open
		}

		try! _socket.connect(to: remoteIP, port: 40030);
		isOpen = true;

		delegate?.masterDidConnect(self);

		_thread.async {
			self.runLoop();
		}
	}

	private func runLoop() {
		while(isOpen) {
			var data = Data();

			let (bytesRead) = try! _socket.read(into: &data);

			guard bytesRead > 0 else {
				// No data received, continue
				continue;
			}

			// Decode the message
			guard let datagram = try? Messages_Datagram(serializedData: Data(data)) else {
				print("Received object was not a datagram...")
				return
			}

			// Handle the datagram; perform internal actions
			switch datagram.type {
			case .close:
				close();
			case .heartbeat:
				// Received a heartbeat. Do nothing.
				break;
			case .ping:
				onPing(datagram.data);
			case .pong:
				onPong(datagram.data);
			default:
				// This is not a system command, pass along to the delegate
				delegate?.master(self, receivedDatagram: datagram)
				break;
			}
		}
	}

	public func close() {
		var datagram = Messages_Datagram();
		datagram.type = .close;

		try! _socket.write(from: datagram.serializedData());
	}
	deinit {
		close();
	}
}

extension MasterClient {
	@objc func requestStatus() {
		var datagram = Messages_Datagram();
		datagram.type = .status;

		try! _socket.write(from: datagram.serializedData());
	}

	func requestLayoutList() {
		var datagram = Messages_Datagram();
		datagram.type = .layoutList;

		try! _socket.write(from: datagram.serializedData());
	}

	func requestLayout(name: String) {
		var layoutName = Messages_LayoutName();
		layoutName.name = name;

		var datagram = Messages_Datagram();
		datagram.type = .layoutOpen;
		datagram.data = try! Google_Protobuf_Any(message: layoutName);

		try! _socket.write(from: datagram.serializedData());
	}

	func createLayout(withName name: String) {
		var layoutName = Messages_LayoutName();
		layoutName.name = name;

		var datagram = Messages_Datagram();
		datagram.type = .layoutCreate;
		datagram.data = try! Google_Protobuf_Any(message: layoutName);

		try! _socket.write(from: datagram.serializedData());
	}

	func deleteLayout(withName name: String) {
		var layoutName = Messages_LayoutName();
		layoutName.name = name;

		var datagram = Messages_Datagram();
		datagram.type = .layoutDelete;
		datagram.data = try! Google_Protobuf_Any(message: layoutName);

		try! _socket.write(from: datagram.serializedData());
	}

	func openLayout(withName name: String) {
		var layoutName = Messages_LayoutName();
		layoutName.name = name;

		var datagram = Messages_Datagram();
		datagram.type = .layoutOpen;
		datagram.data = try! Google_Protobuf_Any(message: layoutName);

		try! _socket.write(from: datagram.serializedData());
	}

	func updateLayout(updatedLayout layout: Layout) {
		var datagram = Messages_Datagram();
		datagram.type = .layoutUpdate;
		datagram.data = try! Google_Protobuf_Any(message: layout.asMessage());

		try! _socket.write(from: datagram.serializedData());

		Log.info("Layout \(layout.name) updated on master")
	}
}

// MARK: - Ping Pong
extension MasterClient {

	/// Tests the connection speed by emitting a ping to the remote.
	/// Upon reception of the response, the time since the first send
	/// will be printed in the logs.
	func ping() {

		var ping = Messages_Ping();
		ping.time = UInt64(Date().timeIntervalSince1970 * 1000.0);

		var datagram = Messages_Datagram();
		datagram.type = .ping;
		datagram.data = try! Google_Protobuf_Any(message: ping);

		try! _socket.write(from: datagram.serializedData());
	}

	/// Called everytime we rerceive a ping message from the remote.
	/// Protocol is to respond directly with the same content
	func onPing(_ data: SwiftProtobuf.Google_Protobuf_Any) {
		// Build the pong datagram
		var datagram = Messages_Datagram();
		datagram.type = .pong;
		datagram.data = data;

		// Send the pond
		try! _socket.write(from: datagram.serializedData());
	}

	/// Called when the response to a previously sent ping is received
	func onPong(_ data: SwiftProtobuf.Google_Protobuf_Any) {
		// Decode the message
		let pong = try! Messages_Ping(unpackingAny: data);
		let now = UInt64(Date().timeIntervalSince1970 * 1000.0);

		let duration = now - pong.time;

		Log.info("Ping-pong with Master in \(duration) milliseconds");
	}
}

