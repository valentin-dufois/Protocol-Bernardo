//
//  B-501.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B501_h
#define B501_h

#include "../../Behaviour.hpp"

class B501 : public Behaviour {
public:
	B501() : Behaviour(501,		// ID
		5,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50100 // S-501-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B501_h */
