//
//  B-161.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_161_hpp
#define B_161_hpp

#ifdef B161
#undef B161
#endif

#include "../../Behaviour.hpp"

class B161: public Behaviour {
public:
    B161(): Behaviour(161,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            156,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_161_hpp */
