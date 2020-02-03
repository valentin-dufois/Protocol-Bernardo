//
//  B-170.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_170_hpp
#define B_170_hpp

#ifdef B170
#undef B170
#endif

#include "../../Behaviour.hpp"

class B170: public Behaviour {
public:
    B170(): Behaviour(170,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            167,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_170_hpp */
