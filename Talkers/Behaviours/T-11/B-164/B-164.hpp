//
//  B-164.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_164_hpp
#define B_164_hpp

#ifdef B164
#undef B164
#endif

#include "../../Behaviour.hpp"

class B164: public Behaviour {
public:
    B164(): Behaviour(164,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            160,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_164_hpp */
