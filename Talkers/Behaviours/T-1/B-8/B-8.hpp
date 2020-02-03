//
//  B-8.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_8_hpp
#define B_8_hpp

#ifdef B8
#undef B8
#endif

#include "../../Behaviour.hpp"

class B8: public Behaviour {
public:
    B8(): Behaviour(8,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            7,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_8_hpp */
