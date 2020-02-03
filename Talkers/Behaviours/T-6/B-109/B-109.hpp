//
//  B-109.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_109_hpp
#define B_109_hpp

#ifdef B109
#undef B109
#endif

#include "../../Behaviour.hpp"

class B109: public Behaviour {
public:
    B109(): Behaviour(109,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            91,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_109_hpp */
