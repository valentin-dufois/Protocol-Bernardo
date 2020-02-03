//
//  B-177.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_177_hpp
#define B_177_hpp

#ifdef B177
#undef B177
#endif

#include "../../Behaviour.hpp"

class B177: public Behaviour {
public:
    B177(): Behaviour(177,	// ID
        13,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            176,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_177_hpp */
