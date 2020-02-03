//
//  B-90.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_90_hpp
#define B_90_hpp

#ifdef B90
#undef B90
#endif

#include "../../Behaviour.hpp"

class B90: public Behaviour {
public:
    B90(): Behaviour(90,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            70,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_90_hpp */
