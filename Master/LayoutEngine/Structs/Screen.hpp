//
//  Screen.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Screen_h
#define Screen_h

#include "../../../Common/Network/Messages/messages.hpp"
#include "../../../Common/Utils.hpp"

namespace pb {
namespace layout {

struct Screen {
	/// The name of the screen
	std::string name;

	/// The screen UID, matching its real-world equivalent.
	std::string uid;

	/// The position of the screen
	maths::vec3 position;

	/// The orientation of the screen
	maths::vec3 orientation;

	/// The dimensions of the screen in cm
	maths::vec2 size;

	Screen() = default;

	Screen(const network::messages::Screen &message) {
		name = message.name();
		uid = message.uid();
		position = maths::fromMessage(message.position());
		orientation = maths::fromMessage(message.orientation());
		size = maths::fromMessage(message.size());
	}

	operator network::messages::Screen () {
		network::messages::Screen message;

		message.set_name(name);
		message.set_uid(uid);
		message.set_allocated_position(maths::asMessage(position));
		message.set_allocated_orientation(maths::asMessage(orientation));
		message.set_allocated_size(maths::asMessage(size));

		return message;
	}
};

} /* ::layout */
} /* ::pb */


#endif /* Screen_h */
