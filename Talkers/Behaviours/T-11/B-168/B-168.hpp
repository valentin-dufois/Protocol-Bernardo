//
//  B-168.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_168_hpp
#define B_168_hpp

#ifdef B168
#undef B168
#endif

#include "../../Behaviour.hpp"

class B168: public Behaviour {
public:
    B168(): Behaviour(168,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            166,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_168_hpp */
