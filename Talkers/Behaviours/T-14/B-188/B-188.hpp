//
//  B-188.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_188_hpp
#define B_188_hpp

#ifdef B188
#undef B188
#endif

#include "../../Behaviour.hpp"

class B188: public Behaviour {
public:
    B188(): Behaviour(188,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            191,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_188_hpp */
