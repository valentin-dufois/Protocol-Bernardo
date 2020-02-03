//
//  B-144.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_144_hpp
#define B_144_hpp

#ifdef B144
#undef B144
#endif

#include "../../Behaviour.hpp"

class B144: public Behaviour {
public:
    B144(): Behaviour(144,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            131,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_144_hpp */
