//
//  B-1201.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_1201_hpp
#define B_1201_hpp


#include "../../Behaviour.hpp"

class B1201 : public Behaviour {
public:
	B1201() : Behaviour(1201,	// ID
		12,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		120100 // S-1200-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_1201_hpp */
