//
//  B-111.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_111_hpp
#define B_111_hpp

#ifdef B111
#undef B111
#endif

#include "../../Behaviour.hpp"

class B111: public Behaviour {
public:
    B111(): Behaviour(111,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            93,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_111_hpp */
