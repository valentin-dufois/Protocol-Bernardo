//
//  Screen.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Screen_h
#define Screen_h

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
};


#endif /* Screen_h */
