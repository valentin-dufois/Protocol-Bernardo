//
//  B-94.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_94_hpp
#define B_94_hpp

#ifdef B94
#undef B94
#endif

#include "../../Behaviour.hpp"

class B94: public Behaviour {
public:
    B94(): Behaviour(94,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            75,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_94_hpp */
