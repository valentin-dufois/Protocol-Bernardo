//
//  B-13.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_13_hpp
#define B_13_hpp

#ifdef B13
#undef B13
#endif

#include "../../Behaviour.hpp"

class B13: public Behaviour {
public:
    B13(): Behaviour(13,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            13,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_13_hpp */
