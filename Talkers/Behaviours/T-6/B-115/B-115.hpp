//
//  B-115.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_115_hpp
#define B_115_hpp

#ifdef B115
#undef B115
#endif

#include "../../Behaviour.hpp"

class B115: public Behaviour {
public:
    B115(): Behaviour(115,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            99,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_115_hpp */
