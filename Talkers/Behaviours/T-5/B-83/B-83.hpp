//
//  B-83.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_83_hpp
#define B_83_hpp

#ifdef B83
#undef B83
#endif

#include "../../Behaviour.hpp"

class B83: public Behaviour {
public:
    B83(): Behaviour(83,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            63,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_83_hpp */
