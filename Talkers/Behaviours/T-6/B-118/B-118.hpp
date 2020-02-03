//
//  B-118.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_118_hpp
#define B_118_hpp

#ifdef B118
#undef B118
#endif

#include "../../Behaviour.hpp"

class B118: public Behaviour {
public:
    B118(): Behaviour(118,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            103,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_118_hpp */
