//
//  B-310.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_310_hpp
#define B_310_hpp

#ifdef B310
#undef B310
#endif

#include "../../Behaviour.hpp"

class B310: public Behaviour {
public:
	B310(): Behaviour(310,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31000, // S-310-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_310_hpp */
