//
//  B-135.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_135_hpp
#define B_135_hpp

#ifdef B135
#undef B135
#endif

#include "../../Behaviour.hpp"

class B135: public Behaviour {
public:
    B135(): Behaviour(135,	// ID
        7,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            121,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_135_hpp */
