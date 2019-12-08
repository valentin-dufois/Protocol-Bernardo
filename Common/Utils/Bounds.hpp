//
//  Bounds.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-07.
//

#ifndef Bounds_h
#define Bounds_h

#include <limits>
#include "maths.hpp"

namespace pb {

struct Bounds {
	double minX = std::numeric_limits<double>::min();
	double maxX = std::numeric_limits<double>::max();

	double minZ = std::numeric_limits<double>::min();
	double maxZ = std::numeric_limits<double>::max();

	bool fit(const maths::vec3 &v) const {
		return v.x > minX && v.x < maxX && v.z > minZ && v.z < maxZ;
	}
};

} /* ::pb */

#endif /* Bounds_h */
