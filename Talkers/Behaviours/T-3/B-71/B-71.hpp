//
//  B-71.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_71_hpp
#define B_71_hpp

#ifdef B71
#undef B71
#endif

#include "../../Behaviour.hpp"

class B71: public Behaviour {
public:
    B71(): Behaviour(71,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            51,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_71_hpp */
