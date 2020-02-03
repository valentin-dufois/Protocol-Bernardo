//
//  B-142.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_142_hpp
#define B_142_hpp

#ifdef B142
#undef B142
#endif

#include "../../Behaviour.hpp"

class B142: public Behaviour {
public:
    B142(): Behaviour(142,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            130,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_142_hpp */
