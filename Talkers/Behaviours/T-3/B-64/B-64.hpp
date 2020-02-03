//
//  B-64.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_64_hpp
#define B_64_hpp

#ifdef B64
#undef B64
#endif

#include "../../Behaviour.hpp"

class B64: public Behaviour {
public:
    B64(): Behaviour(64,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            44,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_64_hpp */
