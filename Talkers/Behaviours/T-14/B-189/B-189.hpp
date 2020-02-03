//
//  B-189.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_189_hpp
#define B_189_hpp

#ifdef B189
#undef B189
#endif

#include "../../Behaviour.hpp"

class B189: public Behaviour {
public:
    B189(): Behaviour(189,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            193,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_189_hpp */
