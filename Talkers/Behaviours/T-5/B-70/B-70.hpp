//
//  B-70.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_70_hpp
#define B_70_hpp

#ifdef B70
#undef B70
#endif

#include "../../Behaviour.hpp"

class B70: public Behaviour {
public:
    B70(): Behaviour(70,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            50,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_70_hpp */
