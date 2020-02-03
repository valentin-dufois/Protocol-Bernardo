//
//  B-132.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_132_hpp
#define B_132_hpp

#ifdef B132
#undef B132
#endif

#include "../../Behaviour.hpp"

class B132: public Behaviour {
public:
    B132(): Behaviour(132,	// ID
        7,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            118,
            119,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        _state["RAND"] = rand() % 10;
		return true;
    }
};


#endif /* B_132_hpp */
