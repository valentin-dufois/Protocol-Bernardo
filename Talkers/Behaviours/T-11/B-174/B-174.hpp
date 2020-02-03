//
//  B-174.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_174_hpp
#define B_174_hpp

#ifdef B174
#undef B174
#endif

#include "../../Behaviour.hpp"

class B174: public Behaviour {
public:
    B174(): Behaviour(174,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            172,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_174_hpp */
