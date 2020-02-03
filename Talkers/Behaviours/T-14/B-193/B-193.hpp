//
//  B-193.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_193_hpp
#define B_193_hpp

#ifdef B193
#undef B193
#endif

#include "../../Behaviour.hpp"

class B193: public Behaviour {
public:
    B193(): Behaviour(193,	// ID
        14,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            197,
            199,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        pb::Body * bodyA = machine->arena()->getBody(std::get<std::string>(machine->getTree()->state["BODY_ID_A"]));
		pb::Body * bodyB = machine->arena()->getBody(std::get<std::string>(machine->getTree()->state["BODY_ID_B"]));

		if(bodyA == nullptr || bodyB == nullptr) {
			_state["STILL_CLOSE"] = false;
			return true;
		}

		if(glm::distance(bodyA->skeleton()->centerOfMass, bodyB->skeleton()->centerOfMass) < 500)
			_state["STILL_CLOSE"] = true;

		return true;
    }
};


#endif /* B_193_hpp */
