//
//  B-172.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_172_hpp
#define B_172_hpp

#ifdef B172
#undef B172
#endif

#include "../../Behaviour.hpp"

class B172: public Behaviour {
public:
    B172(): Behaviour(172,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            169,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_172_hpp */
