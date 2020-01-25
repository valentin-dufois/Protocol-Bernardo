//
//  B-301.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_301_hpp
#define B_301_hpp

#ifdef B301
#undef B301
#endif

#include "../../Behaviour.hpp"

class B301: public Behaviour {
public:
	B301(): Behaviour(301,	// ID
					  3,		// Tree ID
					  true,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
		"BODY_ID_A",
		"BODY_ID_B"
	},
					  {		// Expected outputs
		30100, // S-300-00
	}) {}

	virtual bool execute(Machine * machine) override {

		machine->getTree()->state["BODY_ID_A"] = _state["BODY_ID_A"];
		machine->getTree()->state["BODY_ID_B"] = _state["BODY_ID_B"];

		return true;
	}
};


#endif /* B_301_hpp */
