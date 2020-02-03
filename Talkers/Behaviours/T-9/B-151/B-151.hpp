//
//  B-151.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_151_hpp
#define B_151_hpp

#ifdef B151
#undef B151
#endif

#include "../../Behaviour.hpp"

class B151: public Behaviour {
public:
    B151(): Behaviour(151,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            142,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_151_hpp */
