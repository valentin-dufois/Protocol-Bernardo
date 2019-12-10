//
//  B-504.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B504_h
#define B504_h

#include "../../Behaviour.hpp"

class B504 : public Behaviour {
public:
	B504() : Behaviour(504,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50400 // S-504-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B504_h */
