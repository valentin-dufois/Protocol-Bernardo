//
//  B-602.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B602_h
#define B602_h

#include "../../Behaviour.hpp"

class B602 : public Behaviour {
public:
	B602() : Behaviour(602,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		60200 // S-602-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B602_h */
