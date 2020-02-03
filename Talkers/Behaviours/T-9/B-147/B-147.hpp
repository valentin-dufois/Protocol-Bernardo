//
//  B-147.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_147_hpp
#define B_147_hpp

#ifdef B147
#undef B147
#endif

#include "../../Behaviour.hpp"

class B147: public Behaviour {
public:
    B147(): Behaviour(147,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            136,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_147_hpp */
