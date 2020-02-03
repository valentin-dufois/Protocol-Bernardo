//
//  B-206.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_206_hpp
#define B_206_hpp

#ifdef B206
#undef B206
#endif

#include "../../Behaviour.hpp"

class B206: public Behaviour {
public:
    B206(): Behaviour(206,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            212,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_206_hpp */
