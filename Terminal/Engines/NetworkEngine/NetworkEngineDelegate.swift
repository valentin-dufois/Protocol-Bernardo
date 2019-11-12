//
//  NetworkEngineDelegate.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-29.
//

import SwiftProtobuf

protocol NetworkEngineDelegate: AnyObject {
	func onReceive(status: Messages_MasterStatus);

	func onReceive(layoutList: Messages_LayoutList);

	func onReceive(layout: Messages_Layout);

	func onReceive(trackedBodies: Messages_TrackedBodies);
}
