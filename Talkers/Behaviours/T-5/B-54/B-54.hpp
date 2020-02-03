//
//  B-54.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_54_hpp
#define B_54_hpp

#ifdef B54
#undef B54
#endif

#include "../../Behaviour.hpp"

class B54: public Behaviour {
public:
    B54(): Behaviour(54,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            34,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_54_hpp */
