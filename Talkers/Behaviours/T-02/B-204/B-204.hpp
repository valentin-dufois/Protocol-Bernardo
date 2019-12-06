//
//  B-204.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_204_hpp
#define B_204_hpp


#include "../../Behaviour.hpp"

class B204: public Behaviour {
public:
	B204(): Behaviour(204,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20400, // S-204-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_204_hpp */
