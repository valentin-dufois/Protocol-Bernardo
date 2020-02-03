//
//  B-67.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_67_hpp
#define B_67_hpp

#ifdef B67
#undef B67
#endif

#include "../../Behaviour.hpp"

class B67: public Behaviour {
public:
    B67(): Behaviour(67,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            47,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_67_hpp */
