//
//  OpenNIParser.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef OpenNIParser_hpp
#define OpenNIParser_hpp

#include <vector>
#include <string>

#include "../../libraries.hpp"
#include "Parser.hpp"

namespace pb {
namespace tracker {

class Device;

/// The OpenNIParser scan connected devices to find OpenNI-compatible devices.
class OpenNIParser:
	public Parser,
	public ::openni::OpenNI::DeviceConnectedListener,
	public ::openni::OpenNI::DeviceDisconnectedListener
{
public:
	// MARK: - Singleton

	/**
	 Gives the instance of the OpenNIParser.

	 The parser is a singleton to prevent having multiple instances communicating with
	 the same pool of device at the same time.

	 @return The instance
	 */
	inline static OpenNIParser * getInstance() {
		if(!_instance)
			_instance = new OpenNIParser();

		return _instance;
	};
	
	void start() override;

	~OpenNIParser();

private:
	// MARK: - Singleton

	/** Singleton -> Private constructor */
	OpenNIParser() {}

	/** The unique instance of the PAE */
	static OpenNIParser * _instance;

	// MARK: - OpenNI events

	void onDeviceConnected(const openni::DeviceInfo *) override;

	void onDeviceDisconnected(const openni::DeviceInfo *) override;

	std::vector<std::string> _connectedSerials;
};

} /* ::tracker */
} /* ::pb */

#endif /* OpenNIParser_hpp */
