//
//  B-85.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_85_hpp
#define B_85_hpp

#ifdef B85
#undef B85
#endif

#include "../../Behaviour.hpp"

class B85: public Behaviour {
public:
    B85(): Behaviour(85,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            65,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_85_hpp */
