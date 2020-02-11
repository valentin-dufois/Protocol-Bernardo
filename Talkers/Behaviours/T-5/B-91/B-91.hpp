//
//  B-91.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_91_hpp
#define B_91_hpp

#ifdef B91
#undef B91
#endif

#include "../../Behaviour.hpp"

class B91: public Behaviour {
public:
    B91(): Behaviour(91,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            71,
			9998,
            72,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        _state["MOVING_BODIES_COUNT_INT"] = (int)machine->arena()->movingBodiesCount();
		return true;
    }
};


#endif /* B_91_hpp */
