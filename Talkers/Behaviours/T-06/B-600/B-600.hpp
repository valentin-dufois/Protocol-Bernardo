//
//  B-600.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B600_h
#define B600_h

#ifdef B600
#undef B600
#endif

#include "../../Behaviour.hpp"

class B600 : public Behaviour {
public:
	B600() : Behaviour(600,		// ID
		6,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60000 // S-600-00
		}) {}

	virtual bool execute(Machine * machine) override {
		_state.insert_or_assign("TOTAL_BODY_COUNT", (int)machine->getAllBodyUID().size());
		return true;
	}
};


#endif /* B600_h */
