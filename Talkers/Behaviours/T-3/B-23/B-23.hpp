//
//  B-23.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_23_hpp
#define B_23_hpp

#ifdef B23
#undef B23
#endif

#include "../../Behaviour.hpp"

class B23: public Behaviour {
public:
    B23(): Behaviour(23,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            24,
            25,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: Vérifier si le mouvement a été détecté des deux cotés.
        */

        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

		_state["SUDDEN_MOVE"] = false;

		// Parse past events to find a sudden move
		for(Event &event: machine->eventsHistory()) {
			// Is this a sudden move event
			if(event.name != "SUDDEN_MOVE")
				continue;

			// Did this happened less than five seconds ago ?
			if(std::chrono::duration_cast<std::chrono::seconds>(now - event.time).count() < 5) {
				_state["SUDDEN_MOVE"] = true;
				machine->getTree()->state["SUDDEN_MOVE_SPEED"] = event.values["SUDDEN_MOVE_SPEED"];
				return true;
			}
		}

		return true;
    }
};


#endif /* B_23_hpp */
