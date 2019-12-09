//
//  B-309.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_309_hpp
#define B_309_hpp

#ifdef B309
#undef B309
#endif

#include "../../Behaviour.hpp"

class B309: public Behaviour {
public:
	B309(): Behaviour(309,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		30900, // S-309-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_309_hpp */
