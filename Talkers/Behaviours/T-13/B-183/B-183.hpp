//
//  B-183.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_183_hpp
#define B_183_hpp

#ifdef B183
#undef B183
#endif

#include "../../Behaviour.hpp"

class B183: public Behaviour {
public:
    B183(): Behaviour(183,	// ID
        13,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            185,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_183_hpp */
