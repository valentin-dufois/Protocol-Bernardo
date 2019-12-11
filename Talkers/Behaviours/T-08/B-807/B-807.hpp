//
//  B-807.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_807_hpp
#define B_807_hpp


#include "../../Behaviour.hpp"

class B807 : public Behaviour {
public:
	B807() : Behaviour(807,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80700 // S-807-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_807_hpp */
