//
//  B-1200.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_1200_hpp
#define B_1200_hpp


#include "../../Behaviour.hpp"

class B1200 : public Behaviour {
public:
	B1200() : Behaviour(1200,	// ID
		12,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		120000 // S-1200-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_1200_hpp */
