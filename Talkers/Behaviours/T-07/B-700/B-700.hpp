//
//  B-700.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_700_hpp
#define B_700_hpp


#include "../../Behaviour.hpp"

class B700 : public Behaviour {
public:
	B700() : Behaviour(700,	// ID
		7,		// Tree ID
		true,	// Is tree start ?
		true,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		70000 // S-700-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		// someone is getting very close to the sensor
		return true;
	}
};


#endif /* B_700_hpp */
