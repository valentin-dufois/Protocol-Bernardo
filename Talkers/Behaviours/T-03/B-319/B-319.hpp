//
//  B-319.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_319_hpp
#define B_319_hpp

#ifdef B319
#undef B319
#endif

#include "../../Behaviour.hpp"

class B319: public Behaviour {
public:
	B319(): Behaviour(319,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31900, // S-318-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_319_hpp */
