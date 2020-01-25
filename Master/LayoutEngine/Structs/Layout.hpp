//
//  Layout.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Layout_h
#define Layout_h

#include <vector>
#include <string>

#include "../../../Common/Network/Messages/messages.hpp"

#include "Device.hpp"
#include "Screen.hpp"

namespace pb {
namespace layout {

struct Layout {
	/// The name of the layout
	std::string name;

	/// The devices in the layout
	std::vector<Device *> devices;

	/// The decorations in the layout, such as walls
//	std::vector<Decoration *> decorations;

	Layout() = default;

	Layout(network::messages::Layout * message) {
		name = message->name();

		for(int i = 0; i < message->devices_size(); ++i) {
			devices.push_back(new Device(message->devices(i)));
		}

		message->Clear();
		delete message;
	}

	// MARK: - Operators
	operator network::messages::Layout () const {
		network::messages::Layout message;

		message.set_name(name);

		std::vector<network::messages::Device> devicesMessages;
		for(Device * device: devices) {
			devicesMessages.push_back(*device);
		}

		*message.mutable_devices() = { devicesMessages.begin(), devicesMessages.end() };

		return message;
	}

	~Layout() {
		for(auto it = devices.begin(); it < devices.end(); ++it) {
			delete *it;
		}
	}
};



} /* ::layout */
} /* ::pb */

#endif /* Layout_h */
