//
//  Layout.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Layout_h
#define Layout_h

#include "../../../Common/Messages/messages.hpp"
#include <vector>
#include <string>

#include "Device.hpp"
#include "Screen.hpp"

namespace layout {
struct Layout {
	/// The name of the layout
	std::string name;

	/// The devices in the layout
	std::vector<Device *> devices;

	/// The screens in the layout
	std::vector<Screen *> screens;

	/// The decorations in the layout, such as walls
//	std::vector<Decoration *> decorations;

	Layout() = default;

	Layout(messages::Layout * message) {
		name = message->name();

		for(int i = 0; i < message->devices_size(); ++i) {
			devices.push_back(new Device(message->devices(i)));
		}

		for(int i = 0; i < message->screens_size(); ++i) {
			screens.push_back(new Screen(message->screens(i)));
		}

		message->Clear();
		delete message;
	}

	// MARK: - Operators
	operator messages::Layout () const {
		messages::Layout message;

		message.set_name(name);

		std::vector<messages::Device> devicesMessages;
		for(Device * device: devices) {
			devicesMessages.push_back(*device);
		}

		std::vector<messages::Screen> screensMessages;
		for(Screen * screen: screens) {
			screensMessages.push_back(*screen);
		}

		*message.mutable_devices() = { devicesMessages.begin(), devicesMessages.end() };
		*message.mutable_screens() = { screensMessages.begin(), screensMessages.end() };

		return message;
	}
};
}

#endif /* Layout_h */
