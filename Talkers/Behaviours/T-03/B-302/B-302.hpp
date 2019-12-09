//
//  B-302.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_302_hpp
#define B_302_hpp

#ifdef B302
#undef B302
#endif

#include "../../Behaviour.hpp"

class B302: public Behaviour {
public:
	B302(): Behaviour(302,	// ID
					  3,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		30200, // S-302-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_302_hpp */
