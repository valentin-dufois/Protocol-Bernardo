//
//  B-11.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_11_hpp
#define B_11_hpp

#ifdef B11
#undef B11
#endif

#include "../../Behaviour.hpp"

class B11: public Behaviour {
public:
    B11(): Behaviour(11,	// ID
        2,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            11,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: Vérifie si les interactions sont proches les uns des autres.
        */

        return true;
    }
};


#endif /* B_11_hpp */
