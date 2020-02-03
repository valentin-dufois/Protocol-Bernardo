//
//  B-107.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_107_hpp
#define B_107_hpp

#ifdef B107
#undef B107
#endif

#include "../../Behaviour.hpp"

class B107: public Behaviour {
public:
    B107(): Behaviour(107,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            88,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_107_hpp */
