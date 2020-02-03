//
//  B-63.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_63_hpp
#define B_63_hpp

#ifdef B63
#undef B63
#endif

#include "../../Behaviour.hpp"

class B63: public Behaviour {
public:
    B63(): Behaviour(63,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            43,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_63_hpp */
