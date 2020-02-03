//
//  B-165.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_165_hpp
#define B_165_hpp

#ifdef B165
#undef B165
#endif

#include "../../Behaviour.hpp"

class B165: public Behaviour {
public:
    B165(): Behaviour(165,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            162,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_165_hpp */
