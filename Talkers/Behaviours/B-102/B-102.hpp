//
//  B102.hpp
//  Protocol Bernardo
//
//  Created by Marie-Lou Barbier on 2019-12-02.
//

#ifndef B102_h
#define B102_h

#include "../Behaviour.hpp"

class B102: public Behaviour {
public:
	B102(): Behaviour(102,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		10200 // S-102-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		return true;
	};
};


#endif /* B102_h */
