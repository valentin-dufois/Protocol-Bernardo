//
//  B-22.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_22_hpp
#define B_22_hpp

#ifdef B22
#undef B22
#endif

#include "../../Behaviour.hpp"

class B22: public Behaviour {
public:
    B22(): Behaviour(22,	// ID
        4,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            26,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: On regarde si des personnes entrent dans le champ de captation alors qu'il n'y avait personne avant.
        */

        return true;
    }
};


#endif /* B_22_hpp */
