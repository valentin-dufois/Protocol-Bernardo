//
//  B-900.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_900_hpp
#define B_900_hpp


#include "../../Behaviour.hpp"

class B900 : public Behaviour {
public:
	B900() : Behaviour(900,	// ID
		9,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		90000 // S-900-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_900_hpp */
