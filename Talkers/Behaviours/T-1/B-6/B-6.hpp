//
//  B-6.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_6_hpp
#define B_6_hpp

#ifdef B6
#undef B6
#endif

#include "../../Behaviour.hpp"

class B6: public Behaviour {
public:
    B6(): Behaviour(6,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            5,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_6_hpp */
