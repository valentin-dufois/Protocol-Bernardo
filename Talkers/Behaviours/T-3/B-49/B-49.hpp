//
//  B-49.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_49_hpp
#define B_49_hpp

#ifdef B49
#undef B49
#endif

#include "../../Behaviour.hpp"

class B49: public Behaviour {
public:
    B49(): Behaviour(49,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            30,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: On calcule la vitesse de déplacement de l'interacteur lors du mouvement brusque.
        */

        _state["SUDDEN_MOVE_SPEED_DOUBLE"] = machine->getTree()->state["SUDDEN_MOVE_SPEED"];
		return true;
    }
};


#endif /* B_49_hpp */
