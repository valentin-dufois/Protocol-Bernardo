//
//  B-506.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B506_h
#define B506_h

#include "../../Behaviour.hpp"

class B506 : public Behaviour {
public:
	B506() : Behaviour(506,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50600 // S-506-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B506_h */
