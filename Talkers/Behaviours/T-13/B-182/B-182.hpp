//
//  B-182.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_182_hpp
#define B_182_hpp

#ifdef B182
#undef B182
#endif

#include "../../Behaviour.hpp"

class B182: public Behaviour {
public:
    B182(): Behaviour(182,	// ID
        13,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            183,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_182_hpp */
