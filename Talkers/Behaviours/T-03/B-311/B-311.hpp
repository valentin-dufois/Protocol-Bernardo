//
//  B-311.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_311_hpp
#define B_311_hpp

#ifdef B311
#undef B311
#endif

#include "../../Behaviour.hpp"

class B311: public Behaviour {
public:
	B311(): Behaviour(311,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31100, // S-311-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_311_hpp */
