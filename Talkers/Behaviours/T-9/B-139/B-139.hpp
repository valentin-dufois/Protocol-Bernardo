//
//  B-139.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_139_hpp
#define B_139_hpp

#ifdef B139
#undef B139
#endif

#include "../../Behaviour.hpp"

class B139: public Behaviour {
public:
    B139(): Behaviour(139,	// ID
        9,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            127,
			9997,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: Sortir le nombre d'interacteur détectés depuis le début de l'installation.
        */

        _state["TOTAL_BODIES_COUNT_INT"] = (int)machine->getAllBodyUID().size();
		return true;
    }
};


#endif /* B_139_hpp */
