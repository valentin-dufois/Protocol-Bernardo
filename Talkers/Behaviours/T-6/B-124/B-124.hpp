//
//  B-124.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_124_hpp
#define B_124_hpp

#ifdef B124
#undef B124
#endif

#include "../../Behaviour.hpp"

class B124: public Behaviour {
public:
    B124(): Behaviour(124,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            109,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_124_hpp */
