//
//  B-511.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B511_h
#define B511_h

#include "../../Behaviour.hpp"

class B511 : public Behaviour {
public:
	B511() : Behaviour(511,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		51100 // S-511-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B511_h */
