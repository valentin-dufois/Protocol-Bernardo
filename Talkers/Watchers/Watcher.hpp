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

class Watcher {
public:
	Watcher(const talkers::BehaviourID behaviour, const double &triggerLuck):
	_behaviour(behaviour),
	_triggerLuck(triggerLuck) {};

	virtual void watch(const pb::Arena *) = 0;

	virtual bool hasFoundEvent() {
		float randRes = (float)rand() / (float)RAND_MAX;
		return _foundEvent ? randRes < _triggerLuck : false;
	}

	virtual Event getEvent() = 0;

protected:

	talkers::BehaviourID _behaviour;

	bool _foundEvent = false;

	double _triggerLuck = 1.0;
};

#endif /* Watcher_h */
