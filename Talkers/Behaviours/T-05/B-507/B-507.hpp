//
//  B-507.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B507_h
#define B507_h

#include "../../Behaviour.hpp"

class B507 : public Behaviour {
public:
	B507() : Behaviour(507,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50700 // S-507-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B507_h */
