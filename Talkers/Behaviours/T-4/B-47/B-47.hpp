//
//  B-47.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_47_hpp
#define B_47_hpp

#ifdef B47
#undef B47
#endif

#include "../../Behaviour.hpp"

class B47: public Behaviour {
public:
    B47(): Behaviour(47,	// ID
        4,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            27,
            28,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: On regarde encore si des personnes viennent d'entrer dans le champ de captation de cette machine-ci
        */

        return true;
    }
};


#endif /* B_47_hpp */
