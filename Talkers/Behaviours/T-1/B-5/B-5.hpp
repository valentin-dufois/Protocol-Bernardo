//
//  B-5.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_5_hpp
#define B_5_hpp

#ifdef B5
#undef B5
#endif

#include "../../Behaviour.hpp"

class B5: public Behaviour {
public:
    B5(): Behaviour(5,	// ID
        1,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            4,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_5_hpp */
