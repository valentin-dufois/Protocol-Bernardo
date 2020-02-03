//
//  B-163.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_163_hpp
#define B_163_hpp

#ifdef B163
#undef B163
#endif

#include "../../Behaviour.hpp"

class B163: public Behaviour {
public:
    B163(): Behaviour(163,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            158,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_163_hpp */
