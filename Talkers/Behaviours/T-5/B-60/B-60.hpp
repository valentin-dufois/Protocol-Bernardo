//
//  B-60.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_60_hpp
#define B_60_hpp

#ifdef B60
#undef B60
#endif

#include "../../Behaviour.hpp"

class B60: public Behaviour {
public:
    B60(): Behaviour(60,	// ID
        5,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            40,
            45,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: Vérifier si un mouvement brusque est détecté. Si oui, donner le nombre de mouvements brusques détectés (nombre de personnes ayant bougé) à cet instant précis du dialogue.
        */

        auto [activeBody, bodySpeed] = machine->arena()->mostActiveBody();

		_state["MOVING_BODIES_COUNT_INT"] = 0;

		if(bodySpeed > 5)
			_state["MOVING_BODIES_COUNT_INT"] = 1;

		return true;
    }
};


#endif /* B_60_hpp */
