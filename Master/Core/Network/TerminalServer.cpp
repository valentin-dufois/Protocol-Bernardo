//
//  TerminalServer.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-02.
//

#include <boost/bind.hpp>

#include "TerminalServer.hpp"

#include "../../LayoutEngine/LayoutEngine.hpp"
#include "../../LayoutEngine/Structs/Layout.hpp"
#include "../../TrackingEngine/TrackingEngine.hpp"

namespace pb {
namespace master {

void TerminalServer::socketDidOpen(Socket * newSocket) {

	newSocket->setEmissionType(EmissionType::async);

	Server::socketDidOpen(newSocket);
	// Stop advertising once we have one connection
	endAdvertising();
}

void TerminalServer::socketDidClose(Socket * closedSocket) {
	Server::socketDidClose(closedSocket);

	if(trackingEngine != nullptr)
		trackingEngine->setCalibrationDevices("", "");

	if(socketsCount() == 0) {
		// No more connections to this server, restart the advertiser
		advertise();
	}
}

void TerminalServer::socketDidReceive(Socket * socket, messages::Datagram * datagram) {
	// LOG_DEBUG("Received a datagram");

	messages::Datagram_Type datagramType = datagram->type();

	// Dispatch the datagram
	switch (datagramType) {
			// Commons
		case messages::Datagram_Type_STATUS:
			onStatusRequest(socket);
			break;
			// Layout
		case messages::Datagram_Type_LAYOUT_LIST:
			onLayoutList(socket);
			break;
		case messages::Datagram_Type_LAYOUT_CREATE:
			onLayoutCreate(datagram->mutable_data(), socket);
			break;
		case messages::Datagram_Type_LAYOUT_OPEN:
			onLayoutOpen(datagram->mutable_data(), socket);
			break;
		case messages::Datagram_Type_LAYOUT_CLOSE:
			onLayoutClose(socket);
			break;
		case messages::Datagram_Type_LAYOUT_RENAME:
			onLayoutRename(datagram->mutable_data(), socket);
			break;
		case messages::Datagram_Type_LAYOUT_UPDATE:
			onLayoutUpdate(datagram->mutable_data(), socket);
			break;
		case messages::Datagram_Type_LAYOUT_DELETE:
			onLayoutDelete(datagram->mutable_data(), socket);
			break;

			// Calibration
		case messages::Datagram_Type_CALIBRATION_SET:
			onCalibrationSet(datagram->mutable_data());
			break;
		default:
			LOG_WARN("Received an unimplemented datagram type : " + std::to_string(datagramType));
	}

	delete datagram;
}

void TerminalServer::onStatusRequest(Socket * socket) {
	// Build the status
	messages::MasterStatus status;

	std::string layoutName = layoutEngine->activeLayout() == nullptr ? "" : layoutEngine->activeLayout()->name;

	// Fill in the status
	status.set_activelayout(layoutName);

	for(pb::deviceUID uid: trackingEngine->getConnectedDevicesUID()) {
		status.add_connecteddevices(uid);
	}
	
	// Build the datagram
	protobuf::Message * datagram = makeDatagram(messages::Datagram_Type_STATUS, status);

	socket->send(datagram);
}

// MARK: - Layout methods

void TerminalServer::onLayoutList(Socket * socket) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	// Format the list to protobuf
	messages::LayoutList message;
	for (const std::string &layoutName: layoutEngine->getLayouts()) {
		message.add_layoutname(layoutName);
	}

	// Build the datagram for the response
	protobuf::Message * datagram = makeDatagram(messages::Datagram_Type_LAYOUT_LIST, message);

	socket->send(datagram);
}

void TerminalServer::onLayoutCreate(google::protobuf::Any *data, Socket *socket) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	messages::LayoutName layoutNameMessage;
	data->UnpackTo(&layoutNameMessage);

	layout::Layout * layout = layoutEngine->createLayout(layoutNameMessage.name());

	// Build the datagram for the response
	protobuf::Message * datagram = makeDatagram(messages::Datagram_Type_LAYOUT_OPEN, *layout);

	socket->send(datagram);
}

void TerminalServer::onLayoutOpen(google::protobuf::Any *data, Socket *socket) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	messages::LayoutName layoutNameMessage;
	data->UnpackTo(&layoutNameMessage);

	layout::Layout * layout = layoutEngine->openLayout(layoutNameMessage.name());

	// Build the datagram for the response
	protobuf::Message * datagram = makeDatagram(messages::Datagram_Type_LAYOUT_OPEN, *layout);

	socket->send(datagram);
}

void TerminalServer::onLayoutClose(Socket *) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	// No response here
}

void TerminalServer::onLayoutRename(protobuf::Any *data, Socket *) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	messages::LayoutName layoutNameMessage;
	data->UnpackTo(&layoutNameMessage);

	layoutEngine->renameLayout(layoutNameMessage.name());

	// No response here
}

void TerminalServer::onLayoutUpdate(protobuf::Any *data, Socket *) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	messages::Layout * layoutMessage = new messages::Layout();
	data->UnpackTo(layoutMessage);

	layout::Layout * layout = new layout::Layout(layoutMessage);

	layoutEngine->updateLayout(layout);

	// No response here
}

void TerminalServer::onLayoutDelete(google::protobuf::Any *data, Socket *socket) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}


	messages::LayoutName layoutNameMessage;
	data->UnpackTo(&layoutNameMessage);

	std::vector<std::string> layoutsList = layoutEngine->deleteLayout(layoutNameMessage.name());

	// Format the list to protobuf
	messages::LayoutList message;
	for (const std::string &layoutName: layoutsList) {
		message.add_layoutname(layoutName);
	}

	// Build the datagram for the response
	protobuf::Message * datagram = makeDatagram(messages::Datagram_Type_LAYOUT_LIST, message);

	socket->send(datagram);
}

void TerminalServer::onCalibrationSet(protobuf::Any * data) {
	messages::CalibrationDevices devices;
	data->UnpackTo(&devices);

	if(trackingEngine != nullptr) {
		trackingEngine->setCalibrationDevices(devices.devicea(), devices.deviceb());
	}
}

} /* ::master */
} /* ::pb */
