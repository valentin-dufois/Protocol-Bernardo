//
//  B-192.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_192_hpp
#define B_192_hpp

#ifdef B192
#undef B192
#endif

#include "../../Behaviour.hpp"

class B192: public Behaviour {
public:
    B192(): Behaviour(192,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            195,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_192_hpp */
