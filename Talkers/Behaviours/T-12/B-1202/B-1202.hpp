//
//  B-1202.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_1202_hpp
#define B_1202_hpp


#include "../../Behaviour.hpp"

class B1202 : public Behaviour {
public:
	B1202() : Behaviour(1202,	// ID
		12,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		120200 // S-1202-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_1202_hpp */
