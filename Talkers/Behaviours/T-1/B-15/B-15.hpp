//
//  B-15.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_15_hpp
#define B_15_hpp

#ifdef B15
#undef B15
#endif

#include "../../Behaviour.hpp"

class B15: public Behaviour {
public:
    B15(): Behaviour(15,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            15,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_15_hpp */
