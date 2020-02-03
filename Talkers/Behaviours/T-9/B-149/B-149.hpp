//
//  B-149.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_149_hpp
#define B_149_hpp

#ifdef B149
#undef B149
#endif

#include "../../Behaviour.hpp"

class B149: public Behaviour {
public:
    B149(): Behaviour(149,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            140,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_149_hpp */
