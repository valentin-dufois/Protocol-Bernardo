//
//  B-57.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_57_hpp
#define B_57_hpp

#ifdef B57
#undef B57
#endif

#include "../../Behaviour.hpp"

class B57: public Behaviour {
public:
    B57(): Behaviour(57,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            37,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_57_hpp */
