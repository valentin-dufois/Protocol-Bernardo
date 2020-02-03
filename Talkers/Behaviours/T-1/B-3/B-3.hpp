//
//  B-3.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_3_hpp
#define B_3_hpp

#ifdef B3
#undef B3
#endif

#include "../../Behaviour.hpp"

class B3: public Behaviour {
public:
    B3(): Behaviour(3,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            2,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_3_hpp */
