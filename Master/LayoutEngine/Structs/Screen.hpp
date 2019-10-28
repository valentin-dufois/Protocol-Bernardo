//
//  Screen.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Screen_h
#define Screen_h

#include "../../../Common/Messages/messages.hpp"
#include "../../../Common/Utils/maths.hpp"

struct Screen {
	/// The name of the screen
	std::string name;

	/// The screen UID, matching its real-world equivalent.
	std::string uid;

	/// The position of the screen
	vec3 position;

	/// The orientation of the screen
	vec3 orientation;

	/// The dimensions of the screen in cm
	vec2 size;

	Screen() = default;

	Screen(const messages::Screen &message) {
		name = message.name();
		uid = message.uid();
		position = maths::fromMessage(message.position());
		orientation = maths::fromMessage(message.orientation());
		size = maths::fromMessage(message.size());
	}

	operator messages::Screen () {
		messages::Screen message;

		message.set_name(name);
		message.set_uid(uid);
		message.set_allocated_position(maths::asMessage(position));
		message.set_allocated_orientation(maths::asMessage(orientation));
		message.set_allocated_size(maths::asMessage(size));

		return message;
	}
};


#endif /* Screen_h */
