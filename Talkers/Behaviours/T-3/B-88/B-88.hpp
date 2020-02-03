//
//  B-88.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_88_hpp
#define B_88_hpp

#ifdef B88
#undef B88
#endif

#include "../../Behaviour.hpp"

class B88: public Behaviour {
public:
    B88(): Behaviour(88,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            68,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_88_hpp */
