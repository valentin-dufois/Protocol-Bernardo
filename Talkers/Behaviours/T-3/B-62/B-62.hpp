//
//  B-62.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_62_hpp
#define B_62_hpp

#ifdef B62
#undef B62
#endif

#include "../../Behaviour.hpp"

class B62: public Behaviour {
public:
    B62(): Behaviour(62,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            42,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_62_hpp */
