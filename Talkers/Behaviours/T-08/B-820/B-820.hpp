//
//  B-820.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_820_hpp
#define B_820_hpp


#include "../../Behaviour.hpp"

class B820 : public Behaviour {
public:
	B820() : Behaviour(820,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		82000 // S-820-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_820_hpp */
