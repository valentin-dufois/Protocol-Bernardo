//
//  NetworkEngine.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-15.
//

import Foundation
import Socket
import SwiftProtobuf

/// The netwok engine handles network discovery to find a master on the network and then
/// handles all the emitting/receiving operations for network communication
class NetworkEngine {

	private var _browser = Browser();

	private var _master = MasterClient();

	private var _masterStatusTimer: Timer?

	var master: MasterClient {
		return _master;
	}

	weak var delegate: NetworkEngineDelegate?

	func start() {
		// Set up delegates
		_browser.delegate = self;
		_master.delegate = self;

		// Start the browser
		_browser.startBrowsing();
	}
}


// MARK: - BrowserDelegate
extension NetworkEngine: BrowserDelegate {
	func browser(_: Browser, didFoundMaster: Messages_Endpoint, withIP masterIP: String) {
		// We have a master, stop browsing.
		_browser.stopBrowsing();

		Log.info("Master found. Connecting...")

		// Connect to found master
		_master.open(to: masterIP);
	}
}


// MARK: - Master Handle
extension NetworkEngine {
	func requestLayoutList() {
		_master.requestLayoutList();
	}

	func requestLayout(name: String) {
		_master.requestLayout(name: name);
	}
}


// MARK: - MasterClientDelegate
extension NetworkEngine: MasterClientDelegate {
	func masterDidConnect(_: MasterClient) {
		Log.info("Connected to Master")

		// Upon opening, send a ping
		_master.ping();

		DispatchQueue.main.async {
			self._masterStatusTimer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(self.requestMasterStatus), userInfo: nil, repeats: true)
		}
	}

	@objc public func requestMasterStatus() {
		_master.requestStatus()
	}

	func master(_: MasterClient, receivedDatagram datagram: Messages_Datagram) {
		switch datagram.type {
		case .status:
			onMasterStatus(datagram.data);
		// Layouts
		case .layoutList:
			onLayoutList(datagram.data);
		case .layoutOpen:
			onLayout(datagram.data);
		case .trackedBodies:
			onTrackedBodies(datagram.data);
		default:
			Log.warning("Received unsupported datagram type: \(datagram.type.rawValue)");
		}
	}


	func onMasterStatus(_ data: Google_Protobuf_Any) {
		// Decode the status
		let status = try! Messages_MasterStatus(unpackingAny: data)

		// Store the status until the next one for everyone to access
		App.masterStatus = status

		Log.info("Master Status updated")

		// Pass along to the delegate
		delegate?.onReceive(status: status);
	}

	func onLayoutList(_ data: Google_Protobuf_Any) {
		let layoutList = try! Messages_LayoutList(unpackingAny: data);

		delegate?.onReceive(layoutList: layoutList);
	}

	func onLayout(_ data: Google_Protobuf_Any) {
		let layout = try! Messages_Layout(unpackingAny: data);

		delegate?.onReceive(layout: layout);
	}

	func onTrackedBodies(_ data: Google_Protobuf_Any) {
		let trackedBodies = try! Messages_TrackedBodies(unpackingAny: data)

		delegate?.onReceive(trackedBodies: trackedBodies);
	}
}


// MARK: - Utils
extension NetworkEngine {
	public static func ip(from address: Socket.Address) -> String {
		var ip: String = "";

		switch(address) {
		case .ipv4(let sock):
			ip = String(cString: inet_ntoa(sock.sin_addr)!)
		default:
			print("Only IPV4 supported for now")
			break;
		}

		return ip;
	}
}
