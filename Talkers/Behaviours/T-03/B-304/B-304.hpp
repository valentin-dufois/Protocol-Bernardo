//
//  B-304.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_304_hpp
#define B_304_hpp

#ifdef B304
#undef B304
#endif

#include "../../Behaviour.hpp"

class B304: public Behaviour {
public:
	B304(): Behaviour(304,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		30400, // S-304-00
		30401, // S-304-01
	}) {}

	virtual bool execute(Machine * machine) override {
		_state.insert_or_assign("BODY_COUNT", (int)machine->arena()->count());
		return true;
	}
};


#endif /* B_304_hpp */
