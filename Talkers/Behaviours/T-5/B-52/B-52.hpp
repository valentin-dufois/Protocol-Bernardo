//
//  B-52.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_52_hpp
#define B_52_hpp

#ifdef B52
#undef B52
#endif

#include "../../Behaviour.hpp"

class B52: public Behaviour {
public:
    B52(): Behaviour(52,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            32,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_52_hpp */
