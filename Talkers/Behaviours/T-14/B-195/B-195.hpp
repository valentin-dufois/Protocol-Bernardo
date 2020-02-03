//
//  B-195.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_195_hpp
#define B_195_hpp

#ifdef B195
#undef B195
#endif

#include "../../Behaviour.hpp"

class B195: public Behaviour {
public:
    B195(): Behaviour(195,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            200,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_195_hpp */
