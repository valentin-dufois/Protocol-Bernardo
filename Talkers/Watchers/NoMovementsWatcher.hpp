//
//  NoMovementsWatcher.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-08.
//

#ifndef NoMovementsWatcher_h
#define NoMovementsWatcher_h

#include "../../Common/Utils/Arena.hpp"
#include "Watcher.hpp"

class NoMovementsWatcher: public Watcher {
public:
	NoMovementsWatcher(const talkers::BehaviourID &behaviour, const double &threshold, const double &triggerLuck):
	Watcher(behaviour, triggerLuck), _threshold(threshold) {}

	virtual void watch(pb::Arena * arena) override {
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

#endif /* NoMovementsWatcher_h */
