//
//  B-308.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_308_hpp
#define B_308_hpp

#ifdef B308
#undef B308
#endif

#include "../../Behaviour.hpp"

class B308: public Behaviour {
public:
	B308(): Behaviour(308,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		30800, // S-308-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_308_hpp */
