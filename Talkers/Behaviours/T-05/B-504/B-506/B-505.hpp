//
//  B-505.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B505_h
#define B505_h

#include "../../Behaviour.hpp"

class B505 : public Behaviour {
public:
	B505() : Behaviour(505,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50500 // S-505-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B505_h */
