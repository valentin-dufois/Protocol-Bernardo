//
//  B-105.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_105_hpp
#define B_105_hpp

#ifdef B105
#undef B105
#endif

#include "../../Behaviour.hpp"

class B105: public Behaviour {
public:
    B105(): Behaviour(105,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            86,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_105_hpp */
