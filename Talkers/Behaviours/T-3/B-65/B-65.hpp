//
//  B-65.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_65_hpp
#define B_65_hpp

#ifdef B65
#undef B65
#endif

#include "../../Behaviour.hpp"

class B65: public Behaviour {
public:
    B65(): Behaviour(65,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            46,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_65_hpp */
