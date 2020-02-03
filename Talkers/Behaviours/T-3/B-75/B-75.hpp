//
//  B-75.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_75_hpp
#define B_75_hpp

#ifdef B75
#undef B75
#endif

#include "../../Behaviour.hpp"

class B75: public Behaviour {
public:
    B75(): Behaviour(75,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            54,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_75_hpp */
