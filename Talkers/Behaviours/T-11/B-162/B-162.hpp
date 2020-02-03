//
//  B-162.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_162_hpp
#define B_162_hpp

#ifdef B162
#undef B162
#endif

#include "../../Behaviour.hpp"

class B162: public Behaviour {
public:
    B162(): Behaviour(162,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            157,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_162_hpp */
