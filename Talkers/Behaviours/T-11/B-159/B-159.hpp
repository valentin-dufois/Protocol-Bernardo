//
//  B-159.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_159_hpp
#define B_159_hpp

#ifdef B159
#undef B159
#endif

#include "../../Behaviour.hpp"

class B159: public Behaviour {
public:
    B159(): Behaviour(159,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            154,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_159_hpp */
