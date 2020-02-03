//
//  B-9.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_9_hpp
#define B_9_hpp

#ifdef B9
#undef B9
#endif

#include "../../Behaviour.hpp"

class B9: public Behaviour {
public:
    B9(): Behaviour(9,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            8,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_9_hpp */
