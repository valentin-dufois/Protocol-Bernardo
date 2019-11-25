//
//  OpenNIParser.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-18.
//

#include "OpenNIParser.hpp"

#include "../../../Common/Utils.hpp"
#include "../Devices/OpenNIDevice.hpp"

namespace pb {
namespace tracker {

void OpenNIParser::start() {
	// Initialize OpenNI
	if(openni::OpenNI::initialize() != openni::STATUS_OK) {
		LOG_ERROR(openni::OpenNI::getExtendedError());
		return;
	}

	// Add our event listeners to OpenNI
	openni::OpenNI::addDeviceConnectedListener(this);
	openni::OpenNI::addDeviceDisconnectedListener(this);

	// Init NiTE as we will need it later
	if(nite::NiTE::initialize() != nite::STATUS_OK) {
		LOG_ERROR("Could not itialize NiTE");
	}

	// Execute a parse of already connected devices
	openni::Array<openni::DeviceInfo> availableDevices;
	openni::OpenNI::enumerateDevices(&availableDevices);

	// Parse all the detected devices
	for (int i = 0; i < availableDevices.getSize(); ++i) {
		onDeviceConnected(&availableDevices[i]);
	}
}

OpenNIParser * OpenNIParser::_instance = nullptr;


// MARK: - OpenNI events

void OpenNIParser::onDeviceConnected(const openni::DeviceInfo * deviceInfo) {
	OpenNIDevice * newDevice = new OpenNIDevice(deviceInfo);
	std::string deviceSerial = newDevice->getUID();

	if(std::find(_connectedSerials.begin(), _connectedSerials.end(), deviceSerial) != _connectedSerials.end()) {
		// This device is already connected, ignore it
		delete newDevice;
		return;
	}

	// New device, register its uri and start it
	_connectedSerials.push_back(deviceSerial);
	newDevice->init();

	if(onNewDevice) // Check callback is present
		onNewDevice(newDevice);
}

void OpenNIParser::onDeviceDisconnected(const openni::DeviceInfo *) {
	
}

OpenNIParser::~OpenNIParser() {
	openni::OpenNI::shutdown();
}

} /* ::tracker */
} /* ::pb */
