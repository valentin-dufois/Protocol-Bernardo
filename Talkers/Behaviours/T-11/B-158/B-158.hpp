//
//  B-158.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_158_hpp
#define B_158_hpp

#ifdef B158
#undef B158
#endif

#include "../../Behaviour.hpp"

class B158: public Behaviour {
public:
    B158(): Behaviour(158,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            151,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_158_hpp */
