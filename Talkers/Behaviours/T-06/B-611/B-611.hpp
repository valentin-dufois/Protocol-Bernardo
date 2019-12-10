//
//  B-611.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B611_h
#define B611_h

#include "../../Behaviour.hpp"

class B611 : public Behaviour {
public:
	B611() : Behaviour(611,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		61100 // S-611-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B611_h */
