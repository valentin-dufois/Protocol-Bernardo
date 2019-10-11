//
//  OpenNIDevice.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-18.
//

#include "OpenNIDevice.hpp"

#include <regex>

OpenNIDevice::OpenNIDevice(const openni::DeviceInfo * deviceInfos):
Device(Device::Driver::openni,
	   deviceInfos->getName(),
	   deviceInfos->getUri(),
	   OpenNIDevice::extractSerial(deviceInfos)) {}

void OpenNIDevice::init() {
	LOG_DEBUG(_uri);

	// Set the status as connecting
	_state = starting;

	// Open the device
	if (_device.open(_uri.c_str()) != openni::STATUS_OK)
	{
		LOG_ERROR("Coudle not open the device: " + std::string(openni::OpenNI::getExtendedError()));
		_state = error;
		return;
	}

	// Make sure RGB and depth data are in sync
	_device.setDepthColorSyncEnabled(true);
	// Create the streams

	// Create the color stream
	if(_colorStream.create(_device, openni::SENSOR_COLOR) != openni::STATUS_OK) {
		LOG_ERROR("Coudle not create the color stream:\n%s\n" + std::string(openni::OpenNI::getExtendedError()));
		_state = error;
		return;
	}

	// Set its properties
	openni::VideoMode colorVideoMode;
	colorVideoMode.setResolution(640, 480);
	colorVideoMode.setFps(30);
	colorVideoMode.setPixelFormat(openni::PIXEL_FORMAT_RGB888);
	_colorStream.setVideoMode(colorVideoMode);
	_colorStream.addNewFrameListener(this);
	_colorStream.setMirroringEnabled(true);

	// Create the depth stream
	if(_depthStream.create(_device, openni::SENSOR_DEPTH) != openni::STATUS_OK) {
		LOG_ERROR("Coudle not create the depth stream:\n%s\n" + std::string(openni::OpenNI::getExtendedError()));
		_state = error;
		return;
	}

	// Set its properties
	openni::VideoMode depthVideoMode;
	depthVideoMode.setResolution(640, 480);
	depthVideoMode.setFps(30);
	depthVideoMode.setPixelFormat(openni::PIXEL_FORMAT_DEPTH_1_MM);
	_depthStream.setVideoMode(depthVideoMode);
	_depthStream.addNewFrameListener(this);

	// Set the registration mode
	_device.setImageRegistrationMode(openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR);

	// Start the streams
	if(_colorStream.start() != openni::STATUS_OK) {
		LOG_ERROR("Could not start the color stream");
		_state = error;
		return;
	}

	if(_depthStream.start() != openni::STATUS_OK) {
		LOG_ERROR("Could not start the depth stream");
		_state = error;
		return;
	}

	_state = ready;
}

OpenNIDevice::~OpenNIDevice() {
	if(_state != ready)
		return;
	// Mark the device as closing
	_state = closing;

	// Properly free resources
	_colorStream.stop();
	_colorStream.destroy();
	_depthStream.stop();
	_depthStream.destroy();

	_device.close();
}



// MARK: Misc

std::string OpenNIDevice::extractSerial(const openni::DeviceInfo * deviceInfo) {
	// Get the device URI
	const std::string uri(deviceInfo->getUri());

	// The serial extraction regex.
	// URI to the devices holds a serial parameter. We are using this
	// regex to extract it, allowing for unique identifications of the OpenNI devices
	std::regex regex("serial=(.*?)(&.*)?$");

	// Extract its serial
	std::smatch match;
	if (!std::regex_search(uri.begin(), uri.end(), match, regex)) {
		// Could not extract a serial, skip the device
		std::cout << "Could not get serial for device : " << uri << std::endl;
		return "";
	}

	// mathc[1] is the serial
	return match[1];
}

