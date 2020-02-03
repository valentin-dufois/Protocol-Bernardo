//
//  B-87.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_87_hpp
#define B_87_hpp

#ifdef B87
#undef B87
#endif

#include "../../Behaviour.hpp"

class B87: public Behaviour {
public:
    B87(): Behaviour(87,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            67,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_87_hpp */
