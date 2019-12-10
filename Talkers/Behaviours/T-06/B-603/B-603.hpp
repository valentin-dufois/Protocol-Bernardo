//
//  B-603.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B603_h
#define B603_h

#include "../../Behaviour.hpp"

class B603 : public Behaviour {
public:
	B603() : Behaviour(603,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60300 // S-603-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B603_h */
