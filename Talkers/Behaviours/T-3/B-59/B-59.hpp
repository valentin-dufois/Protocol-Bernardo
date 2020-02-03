//
//  B-59.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_59_hpp
#define B_59_hpp

#ifdef B59
#undef B59
#endif

#include "../../Behaviour.hpp"

class B59: public Behaviour {
public:
    B59(): Behaviour(59,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            39,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: On récupère la vitesse moyenne des interacteurs.

** MANQUE LA VARIABLE DE VITESSE MOYENNE **
        */

        _state["SUDDEN_MOVE_SPEED_TIMES_FROM_AVERAGE_DOUBLE"] = std::get<double>(machine->getTree()->state["SUDDEN_MOVE_SPEED"]) / machine->arena()->averageMoveSpeed();
		return true;
    }
};


#endif /* B_59_hpp */
