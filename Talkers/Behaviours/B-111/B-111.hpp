//
//  B111.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B111_h
#define B111_h

#include "../Behaviour.hpp"

class B111: public Behaviour {
public:
	B111(): Behaviour(111,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		11100 // S-111-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B111_h */
