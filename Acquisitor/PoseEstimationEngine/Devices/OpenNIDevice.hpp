//
//  OpenNIDevice.hpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef OpenNIDevice_hpp
#define OpenNIDevice_hpp

#include "Device.hpp"


/// Represent a device using OpenNI for its connection
class OpenNIDevice:
	public Device,
	public openni::VideoStream::NewFrameListener
{
public:

	// MARK: - Constructor, Destructor & OpenNI

	OpenNIDevice(const openni::DeviceInfo *);

	void init();

	/// Called everytime the color or depth streams receive a new frame
	/// @param stream The stream emitting the new frame
	virtual void onNewFrame(openni::VideoStream &stream) {};

	~OpenNIDevice();

	// MARK: - Accessors

	/// Gives the underlying OpenNI device
	inline openni::Device * getDevice() { return &_device; }

	/// Gives the state of the device
	inline State getState() { return _state; }


private:

	/// Underlying openni device
	openni::Device _device;

	/** The device's color stream */
	openni::VideoStream _colorStream;

	/** The device depth stream */
	openni::VideoStream _depthStream;

	// MARK: Misc

	static std::string extractSerial(const openni::DeviceInfo * deviceInfo);
};

#endif /* OpenNIDevice_hpp */
