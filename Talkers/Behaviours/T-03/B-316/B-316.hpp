//
//  B-316.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_316_hpp
#define B_316_hpp

#ifdef B316
#undef B316
#endif

#include "../../Behaviour.hpp"

class B316: public Behaviour {
public:
	B316(): Behaviour(316,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31600, // S-316-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_316_hpp */
