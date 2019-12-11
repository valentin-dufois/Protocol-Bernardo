//
//  B-809.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_809_hpp
#define B_809_hpp


#include "../../Behaviour.hpp"

class B809 : public Behaviour {
public:
	B809() : Behaviour(809,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80900 // S-809-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_809_hpp */
