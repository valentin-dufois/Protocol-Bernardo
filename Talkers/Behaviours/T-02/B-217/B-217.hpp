//
//  B-217.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_217_hpp
#define B_217_hpp


#include "../../Behaviour.hpp"

class B217: public Behaviour {
public:
	B217(): Behaviour(217,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		21700, // S-217-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_217_hpp */
