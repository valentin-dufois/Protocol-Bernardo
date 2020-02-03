//
//  B-99.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_99_hpp
#define B_99_hpp

#ifdef B99
#undef B99
#endif

#include "../../Behaviour.hpp"

class B99: public Behaviour {
public:
    B99(): Behaviour(99,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            80,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_99_hpp */
