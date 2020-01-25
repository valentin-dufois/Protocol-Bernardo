//
//  B-100.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_100_hpp
#define B_100_hpp


#include "../../Behaviour.hpp"

class B100: public Behaviour {
public:
	B100(): Behaviour(100,	// ID
					  1,		// Tree ID
					  true,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs

	},
					  {		// Expected outputs
		10000, // S-100-00
		10001  // S-100-01
	}) {}

	virtual bool execute(Machine * machine) override {
		_state["NBR_BODY"] = (int)machine->arena()->count();
		return true;
	}
};


#endif /* B_100_hpp */
