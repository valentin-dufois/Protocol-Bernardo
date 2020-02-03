//
//  B-181.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_181_hpp
#define B_181_hpp

#ifdef B181
#undef B181
#endif

#include "../../Behaviour.hpp"

class B181: public Behaviour {
public:
    B181(): Behaviour(181,	// ID
        13,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            182,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_181_hpp */
