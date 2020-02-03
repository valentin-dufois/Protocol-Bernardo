//
//  B-12.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_12_hpp
#define B_12_hpp

#ifdef B12
#undef B12
#endif

#include "../../Behaviour.hpp"

class B12: public Behaviour {
public:
    B12(): Behaviour(12,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            10,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: Relever le nombre de questions posées.
        */

        _state["QUESTIONS_RECEIVED_COUNT"] = std::to_string(machine->receptionHistory().size());

		return true;
    }
};


#endif /* B_12_hpp */
