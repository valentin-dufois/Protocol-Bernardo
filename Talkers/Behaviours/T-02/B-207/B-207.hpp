//
//  B-207.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_207_hpp
#define B_207_hpp


#include "../../Behaviour.hpp"

class B207: public Behaviour {
public:
	B207(): Behaviour(207,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20700, // S-207-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_207_hpp */
