//
//  B-808.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_808_hpp
#define B_808_hpp


#include "../../Behaviour.hpp"

class B808 : public Behaviour {
public:
	B808() : Behaviour(808,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80800 // S-808-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_808_hpp */
