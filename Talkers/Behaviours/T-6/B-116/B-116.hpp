//
//  B-116.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_116_hpp
#define B_116_hpp

#ifdef B116
#undef B116
#endif

#include "../../Behaviour.hpp"

class B116: public Behaviour {
public:
    B116(): Behaviour(116,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            100,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_116_hpp */
