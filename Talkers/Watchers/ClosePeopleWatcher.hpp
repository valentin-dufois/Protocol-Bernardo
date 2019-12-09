//
//  ClosePeopleWatcher.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-08.
//

#ifndef ClosePeopleWatcher_h
#define ClosePeopleWatcher_h

#include "../../Common/Utils/Arena.hpp"
#include "Watcher.hpp"
#include "../../Common/Structs/Body.hpp"

class ClosePeopleWatcher: public Watcher {
public:
	ClosePeopleWatcher(const talkers::BehaviourID &behaviour, const double &threshold, const double &triggerLuck):
	Watcher(behaviour, triggerLuck), _threshold(threshold) {}


	virtual void watch(const pb::Arena * arena) override {
		std::vector<pb::Body *> bodies = arena->getSubset();

		for(int i = 0; i < bodies.size()-1; ++i) {
			pb::Body * bA = bodies[i];

			for(int j = i+1; j < bodies.size(); ++j) {
				if(glm::distance(bA->skeleton()->centerOfMass, bodies[j]->skeleton()->centerOfMass) < _threshold) {

					_bodyIDA = bA->uid;
					_bodyIDB = bodies[j]->uid;
					_foundEvent = true;
				}
			}
		}

		_foundEvent = false;
	}

	virtual Event getEvent() override {
		Event event;
		event.name = "CLOSE_BODY";
		event.behaviour = _behaviour;
		event.values.insert_or_assign("BODY_ID_A", _bodyIDA);
		event.values.insert_or_assign("BODY_ID_B", _bodyIDB);

		return event;
	}

private:

	double _threshold;

	pb::bodyUID _bodyIDA;
	pb::bodyUID _bodyIDB;
};

#endif /* ClosePeopleWatcher_h */
