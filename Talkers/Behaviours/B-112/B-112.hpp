//
//  B112.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B112_h
#define B112_h

#include "../Behaviour.hpp"

class B112: public Behaviour {
public:
	B112(): Behaviour(112,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		11200 // S-112-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B112_h */
