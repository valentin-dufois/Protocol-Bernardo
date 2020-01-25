

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

/// An Arena represent a section of the space covered by PB. It is used to access bodies present in specific locations. An Arena bounds are immutable. To create a new Arena, you must use the `makeSubset` method with the desired bounds. A subset does not need to be contained in its 'parent' Arena.
class Arena {
public:

	Arena(const Arena &a):
	_bodies(a._bodies),
	_mutex(a._mutex),
	_bounds(a._bounds) {}

	Arena(std::map<bodyUID, Body *> * bodies, std::mutex * mutex): Arena(bodies, mutex, Bounds()) {}

	Arena(std::map<bodyUID, Body *> * bodies, std::mutex * mutex, const Bounds &bounds):
	_bodies(bodies),
	_mutex(mutex),
	_bounds(bounds) {}

	/// Gives a "subset" of the current arena with the specified bounds
	/// @param bounds Limits of the subset arena
	inline Arena makeSubset(const Bounds bounds) const {
		return Arena(_bodies, _mutex, _bounds);
	}

	// MARK: - Access

	/// Tell how many bodies are present in this arena.
	unsigned long count() const;

	/// Gives the bodies in the current subset
	std::vector<Body *> getSubset() const;

	/// Gives the Body matching the given UID or nullptr if the UID doesn't match. This method acts on the whole set of bodies, ignoring any bounds/subset
	/// @param uid UID of the body to retrieve
	Body * getBody(const bodyUID &uid) const;

	// MARK: - Intels

	/// The average move speed of all the bodies in the arena in mm/s
	double averageMoveSpeed() const;

	/// Gives the user who's the most active
	std::tuple<Body *, double> mostActiveBody() const;

	// MARK: - Properties
private:
	/// Reference to all the bodies this Arena can access
	std::map<bodyUID, Body *> * _bodies = nullptr;

	/// Reference to the bodies lock shared by all Arenas
	mutable std::mutex * _mutex = nullptr;

	/// The bounds of this arena
	const Bounds _bounds;
};

} /* ::pb */

#endif /* Arena_h */
