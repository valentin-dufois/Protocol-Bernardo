//
//  B-198.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_198_hpp
#define B_198_hpp

#ifdef B198
#undef B198
#endif

#include "../../Behaviour.hpp"

class B198: public Behaviour {
public:
    B198(): Behaviour(198,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            204,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_198_hpp */
