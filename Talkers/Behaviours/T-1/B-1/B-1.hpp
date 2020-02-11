//
//  B-1.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_1_hpp
#define B_1_hpp

#ifdef B1
#undef B1
#endif

#include "../../Behaviour.hpp"

class B1: public Behaviour {
public:
    B1(): Behaviour(1,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            1,
			9999,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: Relever le nombre de personnes.
        */

        _state["BODY_COUNT_INT"] = (int)machine->arena()->count();
		return true;
    }
};


#endif /* B_1_hpp */
