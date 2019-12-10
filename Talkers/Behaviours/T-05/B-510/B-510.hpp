//
//  B-510.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B510_h
#define B510_h

#include "../../Behaviour.hpp"

class B510 : public Behaviour {
public:
	B510() : Behaviour(510,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		51000 // S-510-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B510_h */
