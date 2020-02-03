//
//  B-146.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_146_hpp
#define B_146_hpp

#ifdef B146
#undef B146
#endif

#include "../../Behaviour.hpp"

class B146: public Behaviour {
public:
    B146(): Behaviour(146,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            135,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_146_hpp */
