//
//  B-121.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_121_hpp
#define B_121_hpp

#ifdef B121
#undef B121
#endif

#include "../../Behaviour.hpp"

class B121: public Behaviour {
public:
    B121(): Behaviour(121,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            106,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_121_hpp */
