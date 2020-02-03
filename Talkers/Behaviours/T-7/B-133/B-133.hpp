//
//  B-133.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_133_hpp
#define B_133_hpp

#ifdef B133
#undef B133
#endif

#include "../../Behaviour.hpp"

class B133: public Behaviour {
public:
    B133(): Behaviour(133,	// ID
        7,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            120,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_133_hpp */
