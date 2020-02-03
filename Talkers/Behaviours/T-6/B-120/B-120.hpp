//
//  B-120.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_120_hpp
#define B_120_hpp

#ifdef B120
#undef B120
#endif

#include "../../Behaviour.hpp"

class B120: public Behaviour {
public:
    B120(): Behaviour(120,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            105,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_120_hpp */
