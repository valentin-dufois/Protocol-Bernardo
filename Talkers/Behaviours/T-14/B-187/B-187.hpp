//
//  B-187.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_187_hpp
#define B_187_hpp

#ifdef B187
#undef B187
#endif

#include "../../Behaviour.hpp"

class B187: public Behaviour {
public:
    B187(): Behaviour(187,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            189,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_187_hpp */
