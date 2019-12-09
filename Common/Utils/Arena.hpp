

//
//  Arena.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-07.
//

#ifndef Arena_h
#define Arena_h

#include <mutex>
#include <map>
#include <vector>

#include "../common.hpp"
#include "Bounds.hpp"

namespace pb {

struct Body;

class Arena {
public:

	Arena() = default;

	Arena(std::map<bodyUID, Body *> * bodies, std::mutex * mutex): Arena(bodies, mutex, Bounds()) {}

	Arena(std::map<bodyUID, Body *> * bodies, std::mutex * mutex, const Bounds &bounds):
	_bodies(bodies),
	_mutex(mutex),
	_bounds(bounds) {}

	Arena subset(const Bounds bounds) {
		return Arena(_bodies, _mutex, _bounds);
	}


	// MARK: - Access

	/// Tell how many bodies are tracked.
	unsigned long count() const;

	/// The average move speed of all the bodies in the arena in mm/s
	double averageMoveSpeed() const;

	/// Gives the user who's the most active
	std::tuple<Body *, double> mostActiveBody() const;

	std::vector<Body *> getSubset() const;

	Body * getBody(const bodyUID &uid);

	// MARK: - Properties
private:
	std::map<bodyUID, Body *> * _bodies = nullptr;

	std::mutex * _mutex = nullptr;

	Bounds _bounds;
};

} /* ::pb */

#endif /* Arena_h */
