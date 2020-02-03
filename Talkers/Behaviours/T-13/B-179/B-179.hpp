//
//  B-179.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_179_hpp
#define B_179_hpp

#ifdef B179
#undef B179
#endif

#include "../../Behaviour.hpp"

class B179: public Behaviour {
public:
    B179(): Behaviour(179,	// ID
        13,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            179,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_179_hpp */
