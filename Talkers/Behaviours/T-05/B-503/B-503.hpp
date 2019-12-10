//
//  B-503.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B503_h
#define B503_h

#include "../../Behaviour.hpp"

class B503 : public Behaviour {
public:
	B503() : Behaviour(503,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50300 // S-503-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B503_h */
