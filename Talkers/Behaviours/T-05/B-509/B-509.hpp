//
//  B-509.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B509_h
#define B509_h

#include "../../Behaviour.hpp"

class B509 : public Behaviour {
public:
	B509() : Behaviour(509,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		50900 // S-509-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B509_h */
