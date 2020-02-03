//
//  B-184.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_184_hpp
#define B_184_hpp

#ifdef B184
#undef B184
#endif

#include "../../Behaviour.hpp"

class B184: public Behaviour {
public:
    B184(): Behaviour(184,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
            "BODY_ID_B",
        },
        {		            // Expected outputs
            187,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: La distance entre deux interacteurs est inférieure à un certain seuil.
        */

        machine->getTree()->state["BODY_ID_A"] = _state["BODY_ID_A"];
		machine->getTree()->state["BODY_ID_B"] = _state["BODY_ID_B"];

		return true;
    }
};


#endif /* B_184_hpp */
