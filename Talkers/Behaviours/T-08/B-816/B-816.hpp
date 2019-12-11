//
//  B-816.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_816_hpp
#define B_816_hpp


#include "../../Behaviour.hpp"

class B816 : public Behaviour {
public:
	B816() : Behaviour(816,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81600 // S-816-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_816_hpp */
