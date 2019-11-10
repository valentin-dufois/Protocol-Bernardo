//
//  MasterServer.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-02.
//

#include "MasterServer.hpp"

#include <boost/bind.hpp>

#include "../../LayoutEngine/Structs/Layout.hpp"
#include "../../../Common/CommunicationEngine/Exchanges/Socket.hpp"
#include "../../LayoutEngine/LayoutEngine.hpp"
#include "../../TrackingEngine/TrackingEngine.hpp"

void MasterServer::onClient(Socket * newSocket) {
	// Stop advertising once we have one connection
	endAdvertising();

	// This is a new connection, set it up
	newSocket->onDatagram = [&, newSocket] (google::protobuf::Message * aMessage) {
		onDatagram((messages::Datagram *)aMessage, newSocket);
	};

	newSocket->listen();
}

void MasterServer::onSocketClosed(Socket * closedSocket) {
	if(socketsCount() == 0) {
		// No more connections to this server, restart the advertiser
		advertise();
	}
}

void MasterServer::onDatagram(messages::Datagram * datagram, Socket * socket) {
	LOG_DEBUG("Received a datagram");

	messages::Datagram_Type datagramType = datagram->type();

	// Make sure the datagram is really for us. Master datagram types numbers are comprised between 0-100 (Common) and 200-300 (Master)
	if(datagramType == 0 || (datagramType > 100 && datagramType < 200) || datagramType >= 300) {
		// This datagram isn't for us
		LOG_WARN("Received an unsupported datagram");
		return;
	}

	// Dispatch the datagram
	switch (datagramType) {
			// Commons
		case messages::Datagram_Type_CLOSE:
			socket->close(true); break;
		case messages::Datagram_Type_PING:
			onPing(datagram->mutable_data(), socket);
			break;
		case messages::Datagram_Type_PONG:
			onPong(datagram->mutable_data(), socket);
			break;
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
		default:
			LOG_WARN("Unimplemented datagram type : " + std::to_string(datagramType));
	}
}

void MasterServer::onStatusRequest(Socket * socket) {
	// Build the status
	messages::MasterStatus status;

	std::string layoutName = layoutEngine->activeLayout() == nullptr ? "" : layoutEngine->activeLayout()->name;

	// Fill in the status
	status.set_activelayout(layoutName);

	for(pb::deviceUID uid: trackingEngine->getConnectedDevicesUID()) {
		status.add_connecteddevices(uid);
	}
	
	// Build the datagram
	protobuf::Message * datagram = messages::makeDatagram(messages::Datagram_Type_STATUS, status);

	socket->send(datagram);

	// Release
	datagram->Clear();
	delete datagram;
}

// MARK: - Layout methods

void MasterServer::onLayoutList(Socket * socket) {
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
	protobuf::Message * datagram = messages::makeDatagram(messages::Datagram_Type_LAYOUT_LIST, message);

	socket->send(datagram);

	// Release
	datagram->Clear();
	delete datagram;
}

void MasterServer::onLayoutCreate(google::protobuf::Any *data, Socket *socket) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	messages::LayoutName layoutNameMessage;
	data->UnpackTo(&layoutNameMessage);

	layout::Layout * layout = layoutEngine->createLayout(layoutNameMessage.name());

	// Build the datagram for the response
	protobuf::Message * datagram = messages::makeDatagram(messages::Datagram_Type_LAYOUT_OPEN, *layout);

	socket->send(datagram);

	// Release
	datagram->Clear();
	delete datagram;
}

void MasterServer::onLayoutOpen(google::protobuf::Any *data, Socket *socket) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	messages::LayoutName layoutNameMessage;
	data->UnpackTo(&layoutNameMessage);

	layout::Layout * layout = layoutEngine->openLayout(layoutNameMessage.name());

	// Build the datagram for the response
	protobuf::Message * datagram = messages::makeDatagram(messages::Datagram_Type_LAYOUT_OPEN, *layout);

	socket->send(datagram);

	// Release
	datagram->Clear();
	delete datagram;
}

void MasterServer::onLayoutClose(Socket *socket) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	// No response here
}

void MasterServer::onLayoutRename(google::protobuf::Any *data, Socket *socket) {
	if(layoutEngine == nullptr) {
		LOG_ERROR("Cannot perform layout operations if not layout engine is defined.");
		return;
	}

	messages::LayoutName layoutNameMessage;
	data->UnpackTo(&layoutNameMessage);

	layoutEngine->renameLayout(layoutNameMessage.name());

	// No response here
}

void MasterServer::onLayoutUpdate(google::protobuf::Any *data, Socket *socket) {
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

void MasterServer::onLayoutDelete(google::protobuf::Any *data, Socket *socket) {
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
	protobuf::Message * datagram = messages::makeDatagram(messages::Datagram_Type_LAYOUT_LIST, message);

	socket->send(datagram);

	// Release
	datagram->Clear();
	delete datagram;
}
