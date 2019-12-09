//
//  B-318.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_318_hpp
#define B_318_hpp

#ifdef B318
#undef B318
#endif

#include "../../Behaviour.hpp"

class B318: public Behaviour {
public:
	B318(): Behaviour(318,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31800, // S-318-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_318_hpp */
