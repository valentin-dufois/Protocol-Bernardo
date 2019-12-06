//
//  B-101.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_101_hpp
#define B_101_hpp


#include "../../Behaviour.hpp"

class B101: public Behaviour {
public:
	B101(): Behaviour(101,	// ID
					  1,		// Tree ID
					  true,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		10100 // S-100-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_101_hpp */
