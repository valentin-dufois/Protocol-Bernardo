//
//  B-56.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_56_hpp
#define B_56_hpp

#ifdef B56
#undef B56
#endif

#include "../../Behaviour.hpp"

class B56: public Behaviour {
public:
    B56(): Behaviour(56,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            36,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_56_hpp */
