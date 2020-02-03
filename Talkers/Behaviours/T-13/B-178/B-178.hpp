//
//  B-178.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_178_hpp
#define B_178_hpp

#ifdef B178
#undef B178
#endif

#include "../../Behaviour.hpp"

class B178: public Behaviour {
public:
    B178(): Behaviour(178,	// ID
        13,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            177,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_178_hpp */
