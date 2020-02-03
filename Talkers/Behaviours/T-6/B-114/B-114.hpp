//
//  B-114.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_114_hpp
#define B_114_hpp

#ifdef B114
#undef B114
#endif

#include "../../Behaviour.hpp"

class B114: public Behaviour {
public:
    B114(): Behaviour(114,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            98,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_114_hpp */
