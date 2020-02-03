//
//  B-21.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_21_hpp
#define B_21_hpp

#ifdef B21
#undef B21
#endif

#include "../../Behaviour.hpp"

class B21: public Behaviour {
public:
    B21(): Behaviour(21,	// ID
        2,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            22,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_21_hpp */
