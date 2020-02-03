//
//  B-123.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_123_hpp
#define B_123_hpp

#ifdef B123
#undef B123
#endif

#include "../../Behaviour.hpp"

class B123: public Behaviour {
public:
    B123(): Behaviour(123,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            108,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_123_hpp */
