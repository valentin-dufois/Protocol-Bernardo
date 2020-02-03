//
//  B-201.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_201_hpp
#define B_201_hpp

#ifdef B201
#undef B201
#endif

#include "../../Behaviour.hpp"

class B201: public Behaviour {
public:
    B201(): Behaviour(201,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            207,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_201_hpp */
