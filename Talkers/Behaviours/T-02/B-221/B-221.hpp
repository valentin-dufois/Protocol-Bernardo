//
//  B-221.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_221_hpp
#define B_221_hpp


#include "../../Behaviour.hpp"

class B221: public Behaviour {
public:
	B221(): Behaviour(221,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		22100, // S-221-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_221_hpp */
