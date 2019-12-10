//
//  B-609.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B609_h
#define B609_h

#include "../../Behaviour.hpp"

class B609 : public Behaviour {
public:
	B609() : Behaviour(609,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60900 // S-609-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B609_h */
