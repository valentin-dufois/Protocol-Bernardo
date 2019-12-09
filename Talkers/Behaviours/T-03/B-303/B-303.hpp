//
//  B-303.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_303_hpp
#define B_303_hpp

#ifdef B303
#undef B303
#endif

#include "../../Behaviour.hpp"

class B303: public Behaviour {
public:
	B303(): Behaviour(303,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		30300, // S-303-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_303_hpp */
