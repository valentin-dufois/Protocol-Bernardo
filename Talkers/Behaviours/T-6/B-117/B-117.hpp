//
//  B-117.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_117_hpp
#define B_117_hpp

#ifdef B117
#undef B117
#endif

#include "../../Behaviour.hpp"

class B117: public Behaviour {
public:
    B117(): Behaviour(117,	// ID
        6,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            102,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_117_hpp */
