//
//  B-14.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_14_hpp
#define B_14_hpp

#ifdef B14
#undef B14
#endif

#include "../../Behaviour.hpp"

class B14: public Behaviour {
public:
    B14(): Behaviour(14,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            14,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_14_hpp */
