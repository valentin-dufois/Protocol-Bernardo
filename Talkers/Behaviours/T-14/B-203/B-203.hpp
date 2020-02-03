//
//  B-203.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_203_hpp
#define B_203_hpp

#ifdef B203
#undef B203
#endif

#include "../../Behaviour.hpp"

class B203: public Behaviour {
public:
    B203(): Behaviour(203,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            210,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_203_hpp */
