//
//  B-155.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_155_hpp
#define B_155_hpp

#ifdef B155
#undef B155
#endif

#include "../../Behaviour.hpp"

class B155: public Behaviour {
public:
    B155(): Behaviour(155,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            148,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_155_hpp */
