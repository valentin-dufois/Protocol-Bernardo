//
//  B-89.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_89_hpp
#define B_89_hpp

#ifdef B89
#undef B89
#endif

#include "../../Behaviour.hpp"

class B89: public Behaviour {
public:
    B89(): Behaviour(89,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            69,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_89_hpp */
