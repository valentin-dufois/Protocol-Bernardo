//
//  B-608.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B608_h
#define B608_h

#include "../../Behaviour.hpp"

class B608 : public Behaviour {
public:
	B608() : Behaviour(608,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60800 // S-608-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B608_h */
