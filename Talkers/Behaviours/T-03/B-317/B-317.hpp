//
//  B-317.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_317_hpp
#define B_317_hpp

#ifdef B317
#undef B317
#endif

#include "../../Behaviour.hpp"

class B317: public Behaviour {
public:
	B317(): Behaviour(317,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		31700, // S-317-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_317_hpp */
