//
//  B-55.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_55_hpp
#define B_55_hpp

#ifdef B55
#undef B55
#endif

#include "../../Behaviour.hpp"

class B55: public Behaviour {
public:
    B55(): Behaviour(55,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            35,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_55_hpp */
