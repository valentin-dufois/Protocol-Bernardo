//
//  B-7.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_7_hpp
#define B_7_hpp

#ifdef B7
#undef B7
#endif

#include "../../Behaviour.hpp"

class B7: public Behaviour {
public:
    B7(): Behaviour(7,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            6,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_7_hpp */
