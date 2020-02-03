//
//  B-125.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_125_hpp
#define B_125_hpp

#ifdef B125
#undef B125
#endif

#include "../../Behaviour.hpp"

class B125: public Behaviour {
public:
    B125(): Behaviour(125,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            110,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_125_hpp */
