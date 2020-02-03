//
//  B-20.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_20_hpp
#define B_20_hpp

#ifdef B20
#undef B20
#endif

#include "../../Behaviour.hpp"

class B20: public Behaviour {
public:
    B20(): Behaviour(20,	// ID
        2,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            20,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_20_hpp */
