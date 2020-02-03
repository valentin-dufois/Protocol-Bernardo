//
//  B-106.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_106_hpp
#define B_106_hpp

#ifdef B106
#undef B106
#endif

#include "../../Behaviour.hpp"

class B106: public Behaviour {
public:
    B106(): Behaviour(106,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            87,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_106_hpp */
