//
//  Device.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef Device_h
#define Device_h

#include "../../libraries.hpp"
#include <thread>

namespace pb {
namespace tracker {

/// Represent a physical acquisition device
///
/// A dvice subclass must implement all logic regarding connecting
/// to a device and disconnecting properly from it. Disconnection
/// logic must be executed when the destructor is called
class Device {
public:

	// MARK: - Enums

	/**
	 List of driver capable of communicating with acquisition devices
	 */
	enum Driver {
		openni
	};

	/**
	 Current state of a device
	 */
	enum State {
		/** The state of the device is unknown. Used for not connected devices */
		unknown = 0,

		/** An errored occured with the device. This make it unusable. */
		error = 1,

		/** The device is currently being set up */
		starting = 2,

		/** The device is connected and collecting data. Everything's working fine */
		ready = 4,

		/** The connection to the device is beiing closed */
		closing = 5
	};

	const std::string stateLabels[6] = {
		"Unknown",
		"Error",
		"Starting",
		"Ready",
		"Closing"
	};

	// MARK: - Constructor

	Device(const Driver &t, const std::string &aName, const std::string &aURI, const std::string &aUID):
		driver(t),
		_name(aName),
		_uri(aURI),
		_uid(aUID) {}

	// MARK: - Device properties

	/// Gives the display name of the device
	inline std::string getName() const { return _name; }

	/// Gives the UID of the device, usually its serial number
	inline std::string getUID() const { return _uid; }

	/// Give the URI to the physical peripheral on the system
	inline std::string getURI() const { return _uri; }

	// MARK: - Device State

	/// Give the URI to the physical peripheral on the system
	inline State getState() const { return _state; }

	/// The driver used by this device
	const Driver driver;

protected:
	/// The name of the device
	std::string _name;

	/// The URI of the physical peripheral
	std::string _uri;

	/// The UID of the device
	std::string _uid;

	/// Current state of the device
	State _state = starting;

private:
};

} /* ::tracker */
} /* ::pb */

#include "OpenNIDevice.hpp"

#endif /* Device_h */
