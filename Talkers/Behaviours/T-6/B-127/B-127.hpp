//
//  B-127.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_127_hpp
#define B_127_hpp

#ifdef B127
#undef B127
#endif

#include "../../Behaviour.hpp"

class B127: public Behaviour {
public:
    B127(): Behaviour(127,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            112,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_127_hpp */
