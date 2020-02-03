//
//  B-128.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_128_hpp
#define B_128_hpp

#ifdef B128
#undef B128
#endif

#include "../../Behaviour.hpp"

class B128: public Behaviour {
public:
    B128(): Behaviour(128,	// ID
        7,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            113,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: Vérifier la distance entre un interacteur et la Kinect
 + dire Stop.
        */

        return true;
    }
};


#endif /* B_128_hpp */
