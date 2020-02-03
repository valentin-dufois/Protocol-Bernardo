//
//  B-76.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_76_hpp
#define B_76_hpp

#ifdef B76
#undef B76
#endif

#include "../../Behaviour.hpp"

class B76: public Behaviour {
public:
    B76(): Behaviour(76,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            56,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_76_hpp */
