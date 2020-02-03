//
//  B-73.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_73_hpp
#define B_73_hpp

#ifdef B73
#undef B73
#endif

#include "../../Behaviour.hpp"

class B73: public Behaviour {
public:
    B73(): Behaviour(73,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            53,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_73_hpp */
