//
//  B-53.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_53_hpp
#define B_53_hpp

#ifdef B53
#undef B53
#endif

#include "../../Behaviour.hpp"

class B53: public Behaviour {
public:
    B53(): Behaviour(53,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            33,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_53_hpp */
