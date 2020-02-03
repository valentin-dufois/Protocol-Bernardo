//
//  B-72.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_72_hpp
#define B_72_hpp

#ifdef B72
#undef B72
#endif

#include "../../Behaviour.hpp"

class B72: public Behaviour {
public:
    B72(): Behaviour(72,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            52,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_72_hpp */
