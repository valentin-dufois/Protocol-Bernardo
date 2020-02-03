//
//  B-113.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_113_hpp
#define B_113_hpp

#ifdef B113
#undef B113
#endif

#include "../../Behaviour.hpp"

class B113: public Behaviour {
public:
    B113(): Behaviour(113,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            96,
            97,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        _state["RAND"] = rand() % 10;
		return true;
    }
};


#endif /* B_113_hpp */
