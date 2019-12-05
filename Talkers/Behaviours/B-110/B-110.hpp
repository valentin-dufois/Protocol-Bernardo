//
//  B110.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B110_h
#define B110_h

#include "../Behaviour.hpp"

class B110: public Behaviour {
public:
	B110(): Behaviour(110,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		11000 // S-110-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B110_h */
