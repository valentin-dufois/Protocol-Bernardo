//
//  NetworkEngineDelegate.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-29.
//

import SwiftProtobuf

protocol NetworkEngineDelegate: AnyObject {
	func onReceive(status: Pb_Network_Messages_MasterStatus);

	func onReceive(layoutList: Pb_Network_Messages_LayoutList);

	func onReceive(layout: Pb_Network_Messages_Layout);

	func onReceive(trackedBodies: Pb_Network_Messages_TrackedBodies);

	func masterDidDisconnect();
}
