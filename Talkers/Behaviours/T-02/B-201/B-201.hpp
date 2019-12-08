//
//  B-201.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_201_hpp
#define B_201_hpp

#include <chrono>

#include "../../Behaviour.hpp"

class B201: public Behaviour {
public:
	B201(): Behaviour(201,	// ID
					  2,		// Tree ID
					  true,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20100, // S-201-00
		20101, // S-201-01
	}) {}

	virtual bool execute(Machine * machine) override {
		std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

		_state.insert_or_assign("SUDDEN_MOVE", false);

		// Parse past events to find a sudden move
		for(const Event &event: machine->eventsHistory()) {
			// Is this a sudden move event
			if(event.name != "SUDDEN_MOVE")
				continue;

			// Did this happened less than five seconds ago ?
			if(std::chrono::duration_cast<std::chrono::seconds>(now - event.time).count() < 5) {
				_state.insert_or_assign("SUDDEN_MOVE", true);
				machine->getTree()->state.insert_or_assign("SUDDEN_MOVE_SPEED", event.values.at("SUDDEN_MOVE_SPEED"));
				return true;
			}
		}

		return true;
	}
};


#endif /* B_202_hpp */
