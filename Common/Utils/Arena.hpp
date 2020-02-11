

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
	_devices(a._devices) {}

	Arena(std::map<bodyUID, Body *> * bodies, std::mutex * mutex): Arena(bodies, mutex, {}) {}

	Arena(std::map<bodyUID, Body *> * bodies, std::mutex * mutex, const std::vector<pb::deviceUID> &devices):
	_bodies(bodies),
	_mutex(mutex),
	_devices(devices) {}

	/// Gives a "subset" of the current arena with the specified bounds
	/// @param bounds Limits of the subset arena
	inline Arena makeSubset(const std::vector<pb::deviceUID> devices) const {
		return Arena(_bodies, _mutex, devices);
	}

	// MARK: - Access

	/// Tell how many bodies are present in this arena.
	size_t count() const;

	/// Gives the bodies in the current subset
	std::vector<Body *> getSubset() const;

	/// Gives the Body matching the given UID or nullptr if the UID doesn't match. This method acts on the whole set of bodies, ignoring any bounds/subset
	/// @param uid UID of the body to retrieve
	Body * getBody(const bodyUID &uid) const;

	/// Tell if the given body fits in the current Arena
	/// @returns True if the bodyu fit, false otherwise
	bool fitBody(const Body * body) const;

	// MARK: - Intels

	/// The average move speed of all the bodies in the arena in mm/s
	double averageMoveSpeed();

	/// Gives the user who's the most active
	std::tuple<Body *, double> mostActiveBody();

	/// Number of people moving in the arena
	unsigned int movingBodiesCount() const;

	// MARK: - Properties
private:
	/// Reference to all the bodies this Arena can access
	std::map<bodyUID, Body *> * _bodies = nullptr;

	/// Reference to the bodies lock shared by all Arenas
	mutable std::mutex * _mutex = nullptr;

	/// Watched devices list
	const std::vector<pb::deviceUID> _devices;

	double _lastAvgMoveSpeed = -1;
	double _lastMaxMoveSpeed = -1;
};

} /* ::pb */

#endif /* Arena_h */

