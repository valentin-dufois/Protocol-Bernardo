//
//  B-92.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_92_hpp
#define B_92_hpp

#ifdef B92
#undef B92
#endif

#include "../../Behaviour.hpp"

class B92: public Behaviour {
public:
    B92(): Behaviour(92,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            73,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_92_hpp */
