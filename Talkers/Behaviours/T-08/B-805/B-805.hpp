//
//  B-805.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_805_hpp
#define B_805_hpp


#include "../../Behaviour.hpp"

class B805 : public Behaviour {
public:
	B805() : Behaviour(804,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80500 // S-805-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_805_hpp */
