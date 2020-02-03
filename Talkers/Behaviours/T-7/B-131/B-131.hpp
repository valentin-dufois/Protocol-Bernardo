//
//  B-131.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_131_hpp
#define B_131_hpp

#ifdef B131
#undef B131
#endif

#include "../../Behaviour.hpp"

class B131: public Behaviour {
public:
    B131(): Behaviour(131,	// ID
        7,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            116,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_131_hpp */
