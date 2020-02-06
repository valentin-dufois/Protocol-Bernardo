//
//  NewBodyWatcher.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef NewBodyWatcher_h
#define NewBodyWatcher_h

#include "../../Common/Utils/Arena.hpp"
#include "Watcher.hpp"

class NewBodyWatcher: public Watcher {
public:
	NewBodyWatcher(const talkers::BehaviourID &behaviour, const double &triggerLuck):
	Watcher(behaviour, triggerLuck) {}

	virtual void watch(const pb::Arena * arena) override {
		if(arena->count() == 0) {
			_foundEvent = false;
			return;
		}

		_foundEvent = arena->averageMoveSpeed() < _threshold;
	}

	virtual Event getEvent() override {
		Event event;
		event.name = "NO_MOVEMENTS";
		event.behaviour = _behaviour;

		return event;
	}

private:

	double _threshold;
};

#endif /* NewBodyWatcher_h */
