//
//  B-605.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B605_h
#define B605_h

#include "../../Behaviour.hpp"

class B605 : public Behaviour {
public:
	B605() : Behaviour(605,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60500 // S-605-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B605_h */
