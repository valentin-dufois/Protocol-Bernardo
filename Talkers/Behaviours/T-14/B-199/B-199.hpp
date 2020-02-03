//
//  B-199.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_199_hpp
#define B_199_hpp

#ifdef B199
#undef B199
#endif

#include "../../Behaviour.hpp"

class B199: public Behaviour {
public:
    B199(): Behaviour(199,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            205,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_199_hpp */
