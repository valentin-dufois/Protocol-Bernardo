//
//  B-601.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B601_h
#define B601_h

#include "../../Behaviour.hpp"

class B601 : public Behaviour {
public:
	B601() : Behaviour(601,		// ID
		6,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
			"TOTAL_BODY_COUNT"
		},
		{		// Expected outputs
		60100, // S-601-00
		60101 // S-601-01
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B601_h */
