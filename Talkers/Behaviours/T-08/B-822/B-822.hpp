//
//  B-822.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_822_hpp
#define B_822_hpp


#include "../../Behaviour.hpp"

class B822 : public Behaviour {
public:
	B822() : Behaviour(822,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		82200 // S-822-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_822_hpp */
