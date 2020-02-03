//
//  B-130.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_130_hpp
#define B_130_hpp

#ifdef B130
#undef B130
#endif

#include "../../Behaviour.hpp"

class B130: public Behaviour {
public:
    B130(): Behaviour(130,	// ID
        7,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            115,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_130_hpp */
