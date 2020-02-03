//
//  B-110.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_110_hpp
#define B_110_hpp

#ifdef B110
#undef B110
#endif

#include "../../Behaviour.hpp"

class B110: public Behaviour {
public:
    B110(): Behaviour(110,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            92,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_110_hpp */
