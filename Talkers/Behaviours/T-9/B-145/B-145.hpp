//
//  B-145.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_145_hpp
#define B_145_hpp

#ifdef B145
#undef B145
#endif

#include "../../Behaviour.hpp"

class B145: public Behaviour {
public:
    B145(): Behaviour(145,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            133,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_145_hpp */
