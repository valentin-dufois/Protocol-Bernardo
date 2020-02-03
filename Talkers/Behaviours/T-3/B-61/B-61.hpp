//
//  B-61.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_61_hpp
#define B_61_hpp

#ifdef B61
#undef B61
#endif

#include "../../Behaviour.hpp"

class B61: public Behaviour {
public:
    B61(): Behaviour(61,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            41,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_61_hpp */
