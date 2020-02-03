//
//  B-173.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_173_hpp
#define B_173_hpp

#ifdef B173
#undef B173
#endif

#include "../../Behaviour.hpp"

class B173: public Behaviour {
public:
    B173(): Behaviour(173,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            171,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_173_hpp */
