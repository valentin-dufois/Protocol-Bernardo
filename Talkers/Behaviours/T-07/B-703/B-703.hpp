//
//  B-703.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_703_hpp
#define B_703_hpp


#include "../../Behaviour.hpp"

class B703 : public Behaviour {
public:
	B703() : Behaviour(703,	// ID
		7,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		70300 // S-703-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_703_hpp */