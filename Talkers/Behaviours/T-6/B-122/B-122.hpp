//
//  B-122.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_122_hpp
#define B_122_hpp

#ifdef B122
#undef B122
#endif

#include "../../Behaviour.hpp"

class B122: public Behaviour {
public:
    B122(): Behaviour(122,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            107,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_122_hpp */
