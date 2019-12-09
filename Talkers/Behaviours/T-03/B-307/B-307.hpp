//
//  B-307.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_307_hpp
#define B_307_hpp

#ifdef B307
#undef B307
#endif

#include "../../Behaviour.hpp"

class B307: public Behaviour {
public:
	B307(): Behaviour(307,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		30700, // S-307-00
		30701, // S-307-01
	}) {}

	virtual bool execute(Machine * machine) override {

		pb::Body * bodyA = machine->arena()->getBody(machine->getTree()->state.at("BODY_ID_A").getString());
		pb::Body * bodyB = machine->arena()->getBody(machine->getTree()->state.at("BODY_ID_B").getString());

		if(bodyA == nullptr || bodyB == nullptr) {
			_state.insert_or_assign("STILL_CLOSE", false);
			return true;
		}

		if(glm::distance(bodyA->skeleton()->centerOfMass, bodyB->skeleton()->centerOfMass) < 500)
			_state.insert_or_assign("STILL_CLOSE", true);

		return true;
	}
};


#endif /* B_307_hpp */
