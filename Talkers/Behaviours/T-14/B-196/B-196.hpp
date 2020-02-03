//
//  B-196.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_196_hpp
#define B_196_hpp

#ifdef B196
#undef B196
#endif

#include "../../Behaviour.hpp"

class B196: public Behaviour {
public:
    B196(): Behaviour(196,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            201,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_196_hpp */
