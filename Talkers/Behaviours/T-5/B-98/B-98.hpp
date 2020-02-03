//
//  B-98.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_98_hpp
#define B_98_hpp

#ifdef B98
#undef B98
#endif

#include "../../Behaviour.hpp"

class B98: public Behaviour {
public:
    B98(): Behaviour(98,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            79,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_98_hpp */
