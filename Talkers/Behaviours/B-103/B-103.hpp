//
//  B103.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B103_h
#define B103_h

#include "../Behaviour.hpp"

class B103: public Behaviour {
public:
	B103(): Behaviour(103,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		10300 // S-103-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B103_h */
