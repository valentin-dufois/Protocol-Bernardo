//
//  B-108.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_108_hpp
#define B_108_hpp

#ifdef B108
#undef B108
#endif

#include "../../Behaviour.hpp"

class B108: public Behaviour {
public:
    B108(): Behaviour(108,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            89,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_108_hpp */
