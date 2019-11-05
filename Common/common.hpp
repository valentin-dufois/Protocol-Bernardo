//
//  common.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef common_h
#define common_h

#include <string>

// Tells if we are currently compiling on GCC
#define GCC_COMPILER (defined(__GNUC__) && !defined(__clang__))

// MARK: - Type alias

namespace pb {
	using deviceUID = std::string;
	using rawBodyUID = short int;
	using bodyUID = std::string;
}
#endif /* common_h */
