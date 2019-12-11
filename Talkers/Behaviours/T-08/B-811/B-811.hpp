//
//  B-811.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_811_hpp
#define B_811_hpp


#include "../../Behaviour.hpp"

class B811 : public Behaviour {
public:
	B811() : Behaviour(811,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81100 // S-811-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_811_hpp */
