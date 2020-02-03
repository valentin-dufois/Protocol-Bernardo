//
//  B-102.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_102_hpp
#define B_102_hpp

#ifdef B102
#undef B102
#endif

#include "../../Behaviour.hpp"

class B102: public Behaviour {
public:
    B102(): Behaviour(102,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            83,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_102_hpp */
