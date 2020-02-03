//
//  B-141.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_141_hpp
#define B_141_hpp

#ifdef B141
#undef B141
#endif

#include "../../Behaviour.hpp"

class B141: public Behaviour {
public:
    B141(): Behaviour(141,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
            "TOTAL_BODIES_COUNT",
        },
        {		            // Expected outputs
            128,
            129,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: Sortir le nombre d'interacteur détectés depuis le début de l'installation.
        */

        return true;
    }
};


#endif /* B_141_hpp */
