//
//  B-104.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_104_hpp
#define B_104_hpp

#ifdef B104
#undef B104
#endif

#include "../../Behaviour.hpp"

class B104: public Behaviour {
public:
    B104(): Behaviour(104,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            85,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_104_hpp */
