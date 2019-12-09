//
//  B-314.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_314_hpp
#define B_314_hpp

#ifdef B314
#undef B314
#endif

#include "../../Behaviour.hpp"

class B314: public Behaviour {
public:
	B314(): Behaviour(314,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31400, // S-314-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_314_hpp */
