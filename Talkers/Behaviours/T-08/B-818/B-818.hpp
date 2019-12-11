//
//  B-818.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_818_hpp
#define B_818_hpp


#include "../../Behaviour.hpp"

class B818 : public Behaviour {
public:
	B818() : Behaviour(818,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81800 // S-818-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_818_hpp */
