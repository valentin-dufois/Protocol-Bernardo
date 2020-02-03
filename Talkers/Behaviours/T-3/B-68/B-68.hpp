//
//  B-68.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_68_hpp
#define B_68_hpp

#ifdef B68
#undef B68
#endif

#include "../../Behaviour.hpp"

class B68: public Behaviour {
public:
    B68(): Behaviour(68,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            48,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_68_hpp */
