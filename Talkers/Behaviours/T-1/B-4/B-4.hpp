//
//  B-4.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_4_hpp
#define B_4_hpp

#ifdef B4
#undef B4
#endif

#include "../../Behaviour.hpp"

class B4: public Behaviour {
public:
    B4(): Behaviour(4,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            3,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_4_hpp */
