//
//  B-610.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B610_h
#define B610_h

#include "../../Behaviour.hpp"

class B610 : public Behaviour {
public:
	B610() : Behaviour(610,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		61000 // S-610-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B610_h */
