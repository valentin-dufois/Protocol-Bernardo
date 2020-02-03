//
//  B-17.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_17_hpp
#define B_17_hpp

#ifdef B17
#undef B17
#endif

#include "../../Behaviour.hpp"

class B17: public Behaviour {
public:
    B17(): Behaviour(17,	// ID
        2,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            17,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_17_hpp */
