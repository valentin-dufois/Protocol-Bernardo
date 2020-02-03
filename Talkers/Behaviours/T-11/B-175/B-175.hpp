//
//  B-175.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_175_hpp
#define B_175_hpp

#ifdef B175
#undef B175
#endif

#include "../../Behaviour.hpp"

class B175: public Behaviour {
public:
    B175(): Behaviour(175,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            174,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_175_hpp */
