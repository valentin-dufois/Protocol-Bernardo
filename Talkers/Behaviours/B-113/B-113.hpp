//
//  B113.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B113_h
#define B113_h

#include "../Behaviour.hpp"

class B113: public Behaviour {
public:
	B113(): Behaviour(113,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		11300
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B112_h */
