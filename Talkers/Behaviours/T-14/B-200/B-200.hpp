//
//  B-200.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_200_hpp
#define B_200_hpp

#ifdef B200
#undef B200
#endif

#include "../../Behaviour.hpp"

class B200: public Behaviour {
public:
    B200(): Behaviour(200,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            206,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_200_hpp */
