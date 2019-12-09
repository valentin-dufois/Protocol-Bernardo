//
//  B-402.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B402_h
#define B402_h

#include "../../Behaviour.hpp"

class B402 : public Behaviour {
public:
	B402() : Behaviour(402,		// ID
		4,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		40200 // S-402-00
		}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B402_h */
