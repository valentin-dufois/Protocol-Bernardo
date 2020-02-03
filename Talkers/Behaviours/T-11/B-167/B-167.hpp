//
//  B-167.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_167_hpp
#define B_167_hpp

#ifdef B167
#undef B167
#endif

#include "../../Behaviour.hpp"

class B167: public Behaviour {
public:
    B167(): Behaviour(167,	// ID
        11,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            164,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_167_hpp */
