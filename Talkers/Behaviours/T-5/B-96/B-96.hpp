//
//  B-96.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_96_hpp
#define B_96_hpp

#ifdef B96
#undef B96
#endif

#include "../../Behaviour.hpp"

class B96: public Behaviour {
public:
    B96(): Behaviour(96,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            77,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_96_hpp */
