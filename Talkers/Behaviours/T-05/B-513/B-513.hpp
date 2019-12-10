//
//  B-513.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B513_h
#define B513_h

#include "../../Behaviour.hpp"

class B513 : public Behaviour {
public:
	B513() : Behaviour(513,		// ID
		5,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		51300 // S-513-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B513_h */
