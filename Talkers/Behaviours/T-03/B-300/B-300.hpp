//
//  B-300.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_300_hpp
#define B_300_hpp

#ifdef B300
#undef B300
#endif

#include "../../Behaviour.hpp"

class B300: public Behaviour {
public:
	B300(): Behaviour(300,	// ID
					  3,		// Tree ID
					  true,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
		"BODY_ID_A",
		"BODY_ID_B"
	},
					  {		// Expected outputs
		30000, // S-300-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_300_hpp */
