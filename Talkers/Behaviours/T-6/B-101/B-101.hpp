//
//  B-101.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_101_hpp
#define B_101_hpp

#ifdef B101
#undef B101
#endif

#include "../../Behaviour.hpp"

class B101: public Behaviour {
public:
    B101(): Behaviour(101,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            82,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_101_hpp */
