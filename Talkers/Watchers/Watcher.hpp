//
//  Watcher.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-07.
//

#ifndef Watcher_h
#define Watcher_h

#include <cstdlib>
#include <ctime>

#include "../main.hpp"
#include "Event.hpp"

struct Message;

namespace pb {
class Arena;
}

/// A watcher looks for specific behaviour/elements in a given Arena.
///
/// The watch method will effectively look over the given arena but will not tell you if it found an event. You need to call `Watcher::hasFoundEvent()` after to get the result. The result is influenced by the triggerLuck property given to the watcher on creation
class Watcher {
public:
	Watcher(const talkers::BehaviourID behaviour, const double &triggerLuck):
	_behaviour(behaviour),
	_triggerLuck(triggerLuck) {};

	/// Watch the given arena.
	///
	/// @param arena The arena to watch
	virtual void watch(pb::Arena * arena) = 0;

	virtual bool hasFoundEvent() const {
		float randRes = (float)rand() / (float)RAND_MAX;
		return _foundEvent ? randRes < _triggerLuck : false;
	}

	virtual Event getEvent() = 0;

protected:

	const talkers::BehaviourID _behaviour;

	bool _foundEvent = false;

	const double _triggerLuck = 1.0;
};

#endif /* Watcher_h */
