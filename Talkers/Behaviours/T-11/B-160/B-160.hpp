//
//  B-160.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_160_hpp
#define B_160_hpp

#ifdef B160
#undef B160
#endif

#include "../../Behaviour.hpp"

class B160: public Behaviour {
public:
    B160(): Behaviour(160,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            155,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_160_hpp */
