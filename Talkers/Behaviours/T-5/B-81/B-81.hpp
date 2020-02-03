//
//  B-81.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_81_hpp
#define B_81_hpp

#ifdef B81
#undef B81
#endif

#include "../../Behaviour.hpp"

class B81: public Behaviour {
public:
    B81(): Behaviour(81,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            61,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_81_hpp */
