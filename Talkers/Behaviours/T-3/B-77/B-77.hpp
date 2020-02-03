//
//  B-77.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_77_hpp
#define B_77_hpp

#ifdef B77
#undef B77
#endif

#include "../../Behaviour.hpp"

class B77: public Behaviour {
public:
    B77(): Behaviour(77,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            57,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_77_hpp */
