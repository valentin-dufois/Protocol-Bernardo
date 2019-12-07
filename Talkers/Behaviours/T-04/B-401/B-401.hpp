//
//  B-401.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B401_h
#define B401_h

#include "../../Behaviour.hpp"
#include "../../Core/Machine.hpp"

class B401 : public Behaviour {
public:
	B401() : Behaviour(401,		// ID
		4,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		40100 // S-401-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B401_h */
