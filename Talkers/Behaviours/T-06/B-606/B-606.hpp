//
//  B-606.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B606_h
#define B606_h

#include "../../Behaviour.hpp"

class B606 : public Behaviour {
public:
	B606() : Behaviour(606,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60600 // S-606-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B606_h */
