//
//  B-202.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_202_hpp
#define B_202_hpp

#ifdef B202
#undef B202
#endif

#include "../../Behaviour.hpp"

class B202: public Behaviour {
public:
    B202(): Behaviour(202,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            208,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_202_hpp */
