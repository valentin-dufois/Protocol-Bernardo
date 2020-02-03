//
//  B-93.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_93_hpp
#define B_93_hpp

#ifdef B93
#undef B93
#endif

#include "../../Behaviour.hpp"

class B93: public Behaviour {
public:
    B93(): Behaviour(93,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            74,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_93_hpp */
