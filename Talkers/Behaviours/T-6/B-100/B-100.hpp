//
//  B-100.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_100_hpp
#define B_100_hpp

#ifdef B100
#undef B100
#endif

#include "../../Behaviour.hpp"

class B100: public Behaviour {
public:
    B100(): Behaviour(100,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            81,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_100_hpp */
