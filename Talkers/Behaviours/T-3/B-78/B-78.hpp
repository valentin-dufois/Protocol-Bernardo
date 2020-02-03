//
//  B-78.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_78_hpp
#define B_78_hpp

#ifdef B78
#undef B78
#endif

#include "../../Behaviour.hpp"

class B78: public Behaviour {
public:
    B78(): Behaviour(78,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            58,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_78_hpp */
