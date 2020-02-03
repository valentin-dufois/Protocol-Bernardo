//
//  B-205.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_205_hpp
#define B_205_hpp

#ifdef B205
#undef B205
#endif

#include "../../Behaviour.hpp"

class B205: public Behaviour {
public:
    B205(): Behaviour(205,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            211,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_205_hpp */
