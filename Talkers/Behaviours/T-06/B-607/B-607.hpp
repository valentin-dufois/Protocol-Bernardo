//
//  B-607.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B607_h
#define B607_h

#include "../../Behaviour.hpp"

class B607 : public Behaviour {
public:
	B607() : Behaviour(607,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60700 // S-607-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B607_h */
