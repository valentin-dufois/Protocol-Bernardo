//
//  B-80.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_80_hpp
#define B_80_hpp

#ifdef B80
#undef B80
#endif

#include "../../Behaviour.hpp"

class B80: public Behaviour {
public:
    B80(): Behaviour(80,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            60,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_80_hpp */
