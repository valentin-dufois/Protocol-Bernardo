//
//  Layout.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Layout_h
#define Layout_h

#include <vector>

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

	/// the decorations in the layout
//	std::vector<Decoration *> decorations;
};
}

#endif /* Layout_h */
