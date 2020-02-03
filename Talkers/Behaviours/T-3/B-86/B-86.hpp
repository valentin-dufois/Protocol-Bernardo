//
//  B-86.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_86_hpp
#define B_86_hpp

#ifdef B86
#undef B86
#endif

#include "../../Behaviour.hpp"

class B86: public Behaviour {
public:
    B86(): Behaviour(86,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            66,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_86_hpp */
