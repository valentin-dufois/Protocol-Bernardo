//
//  B-153.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_153_hpp
#define B_153_hpp

#ifdef B153
#undef B153
#endif

#include "../../Behaviour.hpp"

class B153: public Behaviour {
public:
    B153(): Behaviour(153,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            146,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_153_hpp */
