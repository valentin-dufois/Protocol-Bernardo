//
//  B-112.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_112_hpp
#define B_112_hpp

#ifdef B112
#undef B112
#endif

#include "../../Behaviour.hpp"

class B112: public Behaviour {
public:
    B112(): Behaviour(112,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            94,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_112_hpp */
