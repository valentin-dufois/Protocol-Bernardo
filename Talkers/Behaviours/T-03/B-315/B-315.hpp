//
//  B-315.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_315_hpp
#define B_315_hpp

#ifdef B315
#undef B315
#endif

#include "../../Behaviour.hpp"

class B315: public Behaviour {
public:
	B315(): Behaviour(315,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31500, // S-315-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_315_hpp */
