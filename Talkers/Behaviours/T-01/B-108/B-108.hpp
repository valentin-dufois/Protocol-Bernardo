//
//  B108.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B108_h
#define B108_h

#include "../../Behaviour.hpp"

class B108: public Behaviour {
public:
	B108(): Behaviour(108,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		10800 // S-108-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B108_h */
