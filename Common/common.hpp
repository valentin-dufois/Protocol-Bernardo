//
//  common.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef common_h
#define common_h

#define TRACKING_ENGINE_RUN_SPEED 15.0 // Times per seconds
#define TRACKING_ENGINE_MERGE_DISTANCE 150.0 // mm
#define TRACKING_ENGINE_BODY_HISTORY_SIZE 2

#define POSE_ENGINE_RUN_SPEED 30.0

// Tells if we are currently compiling on GCC
#define GCC_COMPILER (defined(__GNUC__) && !defined(__clang__))

#include <string>

// MARK: - Type alias

namespace pb {
	using deviceUID = std::string;
	using rawBodyUID = short int;
	using bodyUID = std::string;
}

using uint = unsigned int;


#endif /* common_h */
