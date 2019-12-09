//
//  B-403.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B403_h
#define B403_h

#include "../../Behaviour.hpp"

class B403 : public Behaviour {
public:
	B403() : Behaviour(403,		// ID
		4,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		40300 // S-403-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B403_h */
