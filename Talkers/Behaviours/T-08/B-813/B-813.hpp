//
//  B-813.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_813_hpp
#define B_813_hpp


#include "../../Behaviour.hpp"

class B813 : public Behaviour {
public:
	B813() : Behaviour(813,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81300 // S-813-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_813_hpp */
