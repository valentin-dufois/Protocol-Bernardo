//
//  B-48.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_48_hpp
#define B_48_hpp

#ifdef B48
#undef B48
#endif

#include "../../Behaviour.hpp"

class B48: public Behaviour {
public:
    B48(): Behaviour(48,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            29,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_48_hpp */
