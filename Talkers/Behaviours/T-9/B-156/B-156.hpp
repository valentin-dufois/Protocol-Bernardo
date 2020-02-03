//
//  B-156.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_156_hpp
#define B_156_hpp

#ifdef B156
#undef B156
#endif

#include "../../Behaviour.hpp"

class B156: public Behaviour {
public:
    B156(): Behaviour(156,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            149,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_156_hpp */
