//
//  B-10.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_10_hpp
#define B_10_hpp

#ifdef B10
#undef B10
#endif

#include "../../Behaviour.hpp"

class B10: public Behaviour {
public:
    B10(): Behaviour(10,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            9,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_10_hpp */
