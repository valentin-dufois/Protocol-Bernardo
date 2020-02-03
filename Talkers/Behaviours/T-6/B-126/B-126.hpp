//
//  B-126.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_126_hpp
#define B_126_hpp

#ifdef B126
#undef B126
#endif

#include "../../Behaviour.hpp"

class B126: public Behaviour {
public:
    B126(): Behaviour(126,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            111,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_126_hpp */
