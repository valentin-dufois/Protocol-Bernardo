//
//  B-148.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_148_hpp
#define B_148_hpp

#ifdef B148
#undef B148
#endif

#include "../../Behaviour.hpp"

class B148: public Behaviour {
public:
    B148(): Behaviour(148,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            138,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_148_hpp */
