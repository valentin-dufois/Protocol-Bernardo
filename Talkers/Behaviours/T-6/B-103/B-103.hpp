//
//  B-103.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_103_hpp
#define B_103_hpp

#ifdef B103
#undef B103
#endif

#include "../../Behaviour.hpp"

class B103: public Behaviour {
public:
    B103(): Behaviour(103,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            84,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_103_hpp */
