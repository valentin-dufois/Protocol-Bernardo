//
//  MasterClientDelegate.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-28.
//

import Foundation
import SwiftProtobuf

protocol MasterClientDelegate {
	func masterDidConnect(_: MasterClient);

	func master(_: MasterClient, receivedDatagram: Pb_Network_Messages_Datagram);

	func masterDidDisconnect(_: MasterClient)
}
