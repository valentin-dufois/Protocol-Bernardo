//
//  B-512.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B512_h
#define B512_h

#include "../../Behaviour.hpp"

class B512 : public Behaviour {
public:
	B512() : Behaviour(512,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		51200 // S-512-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B512_h */
