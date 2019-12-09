//
//  B-312.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_312_hpp
#define B_312_hpp

#ifdef B312
#undef B312
#endif

#include "../../Behaviour.hpp"

class B312: public Behaviour {
public:
	B312(): Behaviour(312,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31200, // S-312-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_312_hpp */
