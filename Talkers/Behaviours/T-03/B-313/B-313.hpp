//
//  B-313.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_313_hpp
#define B_313_hpp

#ifdef B313
#undef B313
#endif

#include "../../Behaviour.hpp"

class B313: public Behaviour {
public:
	B313(): Behaviour(313,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31300, // S-313-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_313_hpp */
