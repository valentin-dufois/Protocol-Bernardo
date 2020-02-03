//
//  B-207.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_207_hpp
#define B_207_hpp

#ifdef B207
#undef B207
#endif

#include "../../Behaviour.hpp"

class B207: public Behaviour {
public:
    B207(): Behaviour(207,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            213,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_207_hpp */
