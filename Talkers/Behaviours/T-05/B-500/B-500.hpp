//
//  B-500.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B500_h
#define B500_h

#include "../../Behaviour.hpp"

class B500 : public Behaviour {
public:
	B500() : Behaviour(500,		// ID
		5,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50000 // S-500-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B500_h */
