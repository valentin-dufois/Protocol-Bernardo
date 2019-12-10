//
//  B-514.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B514_h
#define B514_h

#include "../../Behaviour.hpp"

class B514 : public Behaviour {
public:
	B514() : Behaviour(514,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		51400 // S-514-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B514_h */
