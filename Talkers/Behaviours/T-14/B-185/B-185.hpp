//
//  B-185.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_185_hpp
#define B_185_hpp

#ifdef B185
#undef B185
#endif

#include "../../Behaviour.hpp"

class B185: public Behaviour {
public:
    B185(): Behaviour(185,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            188,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_185_hpp */
