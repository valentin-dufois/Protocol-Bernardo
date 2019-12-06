//
//  B-213.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_213_hpp
#define B_213_hpp


#include "../../Behaviour.hpp"

class B213: public Behaviour {
public:
	B213(): Behaviour(213,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		21300, // S-213-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_213_hpp */
