//
//  B-119.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_119_hpp
#define B_119_hpp

#ifdef B119
#undef B119
#endif

#include "../../Behaviour.hpp"

class B119: public Behaviour {
public:
    B119(): Behaviour(119,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            104,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_119_hpp */
