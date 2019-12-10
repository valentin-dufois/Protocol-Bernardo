//
//  B-502.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B502_h
#define B502_h

#include "../../Behaviour.hpp"

class B502 : public Behaviour {
public:
	B502() : Behaviour(502,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50200 // S-502-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B502_h */
