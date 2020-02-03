//
//  B-97.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_97_hpp
#define B_97_hpp

#ifdef B97
#undef B97
#endif

#include "../../Behaviour.hpp"

class B97: public Behaviour {
public:
    B97(): Behaviour(97,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            78,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_97_hpp */
