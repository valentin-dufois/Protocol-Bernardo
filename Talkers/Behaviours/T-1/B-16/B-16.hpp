//
//  B-16.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_16_hpp
#define B_16_hpp

#ifdef B16
#undef B16
#endif

#include "../../Behaviour.hpp"

class B16: public Behaviour {
public:
    B16(): Behaviour(16,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            16,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_16_hpp */
