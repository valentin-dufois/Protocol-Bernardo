//
//  B000.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef B000_h
#define B000_h

#include "../Behaviour.hpp"
#include "../../Core/Machine.hpp"

class B000: public Behaviour {
public:
	B000(): Behaviour(0,		// ID
					  0,		// Tree ID
					  true,	// Is tree start ?
					  true,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
	}) {}

	virtual bool execute(Machine * machine) override {
		machine->print("executing B000...");
		return true;
	}
};


#endif /* B000_h */
