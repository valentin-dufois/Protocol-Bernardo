//
//  B-508.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B508_h
#define B508_h

#include "../../Behaviour.hpp"

class B508 : public Behaviour {
public:
	B508() : Behaviour(508,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50800 // S-508-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B508_h */
