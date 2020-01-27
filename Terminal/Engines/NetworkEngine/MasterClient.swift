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

	init() {
		_socket = try! Socket.create(family: .inet, type: .stream, proto: .tcp);
	}

	public func open(to ip: String) {
		remoteIP = ip;
		
		guard !isOpen else {
			return; // Connection already open
		}

		_socket = try! Socket.create(family: .inet, type: .stream, proto: .tcp);
		try! _socket.connect(to: remoteIP, port: 42030);

		isOpen = true;

		delegate?.masterDidConnect(self);

		_thread.async {
			self.runLoop();
		}
	}

	private func runLoop() {
		while(isOpen) {
			var data = Data();

			do {
				let (bytesRead) = try _socket.read(into: &data);

				guard bytesRead > 0 else {
					// No data received, continue
					continue;
				}
			} catch {
				Log.error("Could not receive data, closing socket");
				Log.error(error.localizedDescription);
				close();
				return
			}

			// Decode the message
			guard let datagram = try? Pb_Network_Messages_Datagram(serializedData: Data(data)) else {
				Log.warning("Received object was not a datagram...")
				continue
			}

			// Handle the datagram; perform internal actions
			switch datagram.type {
			case .close:
				close();
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

	public func send(_ message: Message) {
		do {
			let data = try message.serializedData();
			try _socket.write(from: data);
		} catch {
			Log.error("Could not send data");
			Log.error(error.localizedDescription);

			close()
		}
	}

	public func close() {
		if !isOpen {
			return
		}

		isOpen = false

		_socket.close();

		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .close;

		_ = try? _socket.write(from: datagram.serializedData());

		delegate?.masterDidDisconnect(self);
	}

	deinit {
		close();
	}
}

extension MasterClient {
	@objc func requestStatus() {
		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .status;

		send(datagram);
	}

	func requestLayoutList() {
		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .layoutList;

		send(datagram);
	}

	func requestLayout(name: String) {
		var layoutName = Pb_Network_Messages_LayoutName();
		layoutName.name = name;

		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .layoutOpen;
		datagram.data = try! Google_Protobuf_Any(message: layoutName);

		send(datagram);
	}

	func createLayout(withName name: String) {
		var layoutName = Pb_Network_Messages_LayoutName();
		layoutName.name = name;

		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .layoutCreate;
		datagram.data = try! Google_Protobuf_Any(message: layoutName);

		send(datagram);
	}

	func deleteLayout(withName name: String) {
		var layoutName = Pb_Network_Messages_LayoutName();
		layoutName.name = name;

		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .layoutDelete;
		datagram.data = try! Google_Protobuf_Any(message: layoutName);

		send(datagram);
	}

	func openLayout(withName name: String) {
		var layoutName = Pb_Network_Messages_LayoutName();
		layoutName.name = name;

		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .layoutOpen;
		datagram.data = try! Google_Protobuf_Any(message: layoutName);

		send(datagram);
	}

	func updateLayout(updatedLayout layout: Layout) {
		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .layoutUpdate;
		datagram.data = try! Google_Protobuf_Any(message: layout.asMessage());

		send(datagram);

		Log.info("Layout \(layout.name) updated on master")
	}

	func clearCalibrationDevice() {
		setCalibrationDevices("", "");
	}

	func setCalibrationDevices(_ deviceA: String, _ deviceB: String) {
		var message = Pb_Network_Messages_CalibrationDevices();
		message.deviceA = deviceA;
		message.deviceB = deviceB;

		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .calibrationSet;
		datagram.data = try! Google_Protobuf_Any(message: message);

		send(datagram);

		Log.info("Calibration devices updated")
	}
}

// MARK: - Ping Pong
extension MasterClient {

	/// Tests the connection speed by emitting a ping to the remote.
	/// Upon reception of the response, the time since the first send
	/// will be printed in the logs.
	func ping() {

		var ping = Pb_Network_Messages_Ping();
		ping.time = UInt64(Date().timeIntervalSince1970 * 1000.0);

		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .ping;
		datagram.data = try! Google_Protobuf_Any(message: ping);

		send(datagram);
	}

	/// Called everytime we rerceive a ping message from the remote.
	/// Protocol is to respond directly with the same content
	func onPing(_ data: SwiftProtobuf.Google_Protobuf_Any) {
		// Build the pong datagram
		var datagram = Pb_Network_Messages_Datagram();
		datagram.type = .pong;
		datagram.data = data;

		// Send the pond
		send(datagram);
	}

	/// Called when the response to a previously sent ping is received
	func onPong(_ data: SwiftProtobuf.Google_Protobuf_Any) {
		// Decode the message
		let pong = try! Pb_Network_Messages_Ping(unpackingAny: data);
		let now = UInt64(Date().timeIntervalSince1970 * 1000.0);

		let duration = now - pong.time;

		Log.info("Ping-pong with Master in \(duration) milliseconds");
	}
}

