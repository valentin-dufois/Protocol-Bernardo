//
//  B-152.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_152_hpp
#define B_152_hpp

#ifdef B152
#undef B152
#endif

#include "../../Behaviour.hpp"

class B152: public Behaviour {
public:
    B152(): Behaviour(152,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            144,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_152_hpp */
