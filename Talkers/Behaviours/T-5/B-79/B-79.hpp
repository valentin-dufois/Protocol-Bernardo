//
//  B-79.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_79_hpp
#define B_79_hpp

#ifdef B79
#undef B79
#endif

#include "../../Behaviour.hpp"

class B79: public Behaviour {
public:
    B79(): Behaviour(79,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            59,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_79_hpp */
