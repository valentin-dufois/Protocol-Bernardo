//
//  B-220.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_220_hpp
#define B_220_hpp


#include "../../Behaviour.hpp"

class B220: public Behaviour {
public:
	B220(): Behaviour(220,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		22000, // S-220-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_220_hpp */
