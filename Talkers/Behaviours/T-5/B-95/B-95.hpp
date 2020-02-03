//
//  B-95.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_95_hpp
#define B_95_hpp

#ifdef B95
#undef B95
#endif

#include "../../Behaviour.hpp"

class B95: public Behaviour {
public:
    B95(): Behaviour(95,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            76,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_95_hpp */
