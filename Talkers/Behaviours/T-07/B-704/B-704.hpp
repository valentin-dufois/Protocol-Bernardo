//
//  B-704.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_704_hpp
#define B_704_hpp


#include "../../Behaviour.hpp"

class B704 : public Behaviour {
public:
	B704() : Behaviour(704,	// ID
		7,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		70400 // S-704-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_704_hpp */