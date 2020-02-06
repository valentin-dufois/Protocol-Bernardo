//
//  B-18.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_18_hpp
#define B_18_hpp

#ifdef B18
#undef B18
#endif

#include "../../Behaviour.hpp"

class B18: public Behaviour {
public:
    B18(): Behaviour(18,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        1,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            18,
            19,
            21,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        auto [body, speed] = machine->arena()->mostActiveBody();

		_state["RAND"] = rand() % 100;
		_state["SUDDEN_MOVE_SPEED_DOUBLE"] = speed;
		
		return true;
    }
};


#endif /* B_18_hpp */
