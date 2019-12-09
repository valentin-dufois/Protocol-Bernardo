//
//  SuddenMoveWatcher.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-07.
//

#ifndef SuddenMoveWatcher_hpp
#define SuddenMoveWatcher_hpp

#include <vector>
#include "../../Common/Utils/Arena.hpp"
#include "Watcher.hpp"

class SuddenMoveWatcher: public Watcher {
public:
	SuddenMoveWatcher(const talkers::BehaviourID &behaviour, const double &threshold, const double &triggerLuck):
	Watcher(behaviour, triggerLuck), _threshold(threshold) {}

	virtual void watch(const pb::Arena * arena) override {
		pb::Body * body;
		double speed;

		std::tie(body, speed) = arena->mostActiveBody();

		if(body == nullptr || speed < _threshold) {
			_foundEvent = false;
			return;
		}

		_foundEvent = true;
		_lastMoveSpeed = speed;
	}

	virtual Event getEvent() override {
		Event event;
		event.name = "SUDDEN_MOVE";
		event.behaviour = _behaviour;
		event.values.insert_or_assign("SUDDEN_MOVE_SPEED", _lastMoveSpeed);

		return event;
	}

private:

	double _threshold;

	double _lastMoveSpeed;
};

#endif /* SuddenMoveWatcher_hpp */
