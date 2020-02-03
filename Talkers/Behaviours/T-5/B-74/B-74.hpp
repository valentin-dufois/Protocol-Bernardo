//
//  B-74.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_74_hpp
#define B_74_hpp

#ifdef B74
#undef B74
#endif

#include "../../Behaviour.hpp"

class B74: public Behaviour {
public:
    B74(): Behaviour(74,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            55,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

            return true;
    }
};


#endif /* B_74_hpp */
