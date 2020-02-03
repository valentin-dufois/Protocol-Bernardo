//
//  B-129.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_129_hpp
#define B_129_hpp

#ifdef B129
#undef B129
#endif

#include "../../Behaviour.hpp"

class B129: public Behaviour {
public:
    B129(): Behaviour(129,	// ID
        7,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            114,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_129_hpp */
