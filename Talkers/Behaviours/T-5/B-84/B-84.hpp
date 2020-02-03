//
//  B-84.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_84_hpp
#define B_84_hpp

#ifdef B84
#undef B84
#endif

#include "../../Behaviour.hpp"

class B84: public Behaviour {
public:
    B84(): Behaviour(84,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            64,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_84_hpp */
