//
//  B-306.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_306_hpp
#define B_306_hpp

#ifdef B306
#undef B306
#endif

#include "../../Behaviour.hpp"

class B306: public Behaviour {
public:
	B306(): Behaviour(306,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		30600, // S-306-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_306_hpp */
