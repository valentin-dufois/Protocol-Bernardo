//
//  B104.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B104_h
#define B104_h

#include "../Behaviour.hpp"

class B104: public Behaviour {
public:
	B104(): Behaviour(104,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		10400 // S-104-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B104_h */
