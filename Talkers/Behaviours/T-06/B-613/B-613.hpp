//
//  B-613.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B613_h
#define B613_h

#include "../../Behaviour.hpp"

class B613 : public Behaviour {
public:
	B613() : Behaviour(613,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		61300 // S-613-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B613_h */
