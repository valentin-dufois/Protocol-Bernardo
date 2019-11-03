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

	func master(_: MasterClient, receivedDatagram: Messages_Datagram);
}
