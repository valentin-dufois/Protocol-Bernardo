//
//  B-58.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_58_hpp
#define B_58_hpp

#ifdef B58
#undef B58
#endif

#include "../../Behaviour.hpp"

class B58: public Behaviour {
public:
    B58(): Behaviour(58,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            38,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_58_hpp */
