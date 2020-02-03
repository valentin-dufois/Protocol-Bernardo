//
//  B-180.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_180_hpp
#define B_180_hpp

#ifdef B180
#undef B180
#endif

#include "../../Behaviour.hpp"

class B180: public Behaviour {
public:
    B180(): Behaviour(180,	// ID
        13,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            181,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_180_hpp */
