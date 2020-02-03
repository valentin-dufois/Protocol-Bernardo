//
//  B-197.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_197_hpp
#define B_197_hpp

#ifdef B197
#undef B197
#endif

#include "../../Behaviour.hpp"

class B197: public Behaviour {
public:
    B197(): Behaviour(197,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            203,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_197_hpp */
