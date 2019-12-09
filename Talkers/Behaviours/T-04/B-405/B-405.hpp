//
//  B-405.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B405_h
#define B405_h

#include "../../Behaviour.hpp"

class B405 : public Behaviour {
public:
	B405() : Behaviour(405,		// ID
		4,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		40500 // S-405-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B405_h */
