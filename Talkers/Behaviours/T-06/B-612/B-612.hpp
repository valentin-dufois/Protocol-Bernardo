//
//  B-612.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B612_h
#define B612_h

#include "../../Behaviour.hpp"

class B612 : public Behaviour {
public:
	B612() : Behaviour(612,		// ID
		6,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		61200 // S-612-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B612_h */
