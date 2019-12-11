//
//  B-801.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_801_hpp
#define B_801_hpp


#include "../../Behaviour.hpp"

class B801 : public Behaviour {
public:
	B801() : Behaviour(801,	// ID
		8,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80100 // S-801-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_801_hpp */
