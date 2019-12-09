//
//  B-400.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B400_h
#define B400_h

#include "../../Behaviour.hpp"

class B400 : public Behaviour {
public:
	B400() : Behaviour(400,		// ID
		4,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		40000 // S-400-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B400_h */
