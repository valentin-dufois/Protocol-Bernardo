//
//  B-50.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_50_hpp
#define B_50_hpp

#ifdef B50
#undef B50
#endif

#include "../../Behaviour.hpp"

class B50: public Behaviour {
public:
    B50(): Behaviour(50,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            31,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_50_hpp */
