//
//  B-216.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_216_hpp
#define B_216_hpp


#include "../../Behaviour.hpp"

class B216: public Behaviour {
public:
	B216(): Behaviour(216,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		21600, // S-216-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_216_hpp */
