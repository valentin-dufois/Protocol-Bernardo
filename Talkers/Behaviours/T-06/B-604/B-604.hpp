//
//  B-604.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B604_h
#define B604_h

#include "../../Behaviour.hpp"

class B604 : public Behaviour {
public:
	B604() : Behaviour(604,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60400 // S-604-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B604_h */
