//
//  B107.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B107_h
#define B107_h

#include "../Behaviour.hpp"

class B107: public Behaviour {
public:
	B107(): Behaviour(107,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		10700 // S-107-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B107_h */
