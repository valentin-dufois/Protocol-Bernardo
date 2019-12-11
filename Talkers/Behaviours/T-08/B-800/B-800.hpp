//
//  B-800.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_800_hpp
#define B_800_hpp


#include "../../Behaviour.hpp"

class B800 : public Behaviour {
public:
	B800() : Behaviour(800,	// ID
		8,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80000 // S-800-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_800_hpp */
