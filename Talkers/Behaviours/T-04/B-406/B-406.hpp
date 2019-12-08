//
//  B-406.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B406_h
#define B406_h

#include "../../Behaviour.hpp"
#include "../../Core/Machine.hpp"

class B406 : public Behaviour {
public:
	B406() : Behaviour(406,		// ID
		4,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		40600 // S-403-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B406_h */
