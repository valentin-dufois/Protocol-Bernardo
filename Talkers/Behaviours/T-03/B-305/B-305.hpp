//
//  B-305.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_305_hpp
#define B_305_hpp

#ifdef B305
#undef B305
#endif

#include "../../Behaviour.hpp"

class B305: public Behaviour {
public:
	B305(): Behaviour(305,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		30500, // S-305-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_305_hpp */
