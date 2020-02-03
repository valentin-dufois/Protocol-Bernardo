//
//  B-82.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_82_hpp
#define B_82_hpp

#ifdef B82
#undef B82
#endif

#include "../../Behaviour.hpp"

class B82: public Behaviour {
public:
    B82(): Behaviour(82,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            62,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_82_hpp */
