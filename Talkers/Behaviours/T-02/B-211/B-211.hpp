//
//  B-211.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_211_hpp
#define B_211_hpp

#include "../../Behaviour.hpp"

class B211: public Behaviour {
public:
	B211(): Behaviour(211,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		21100, // S-211-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_211_hpp */
