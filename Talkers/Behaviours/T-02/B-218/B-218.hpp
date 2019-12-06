//
//  B-218.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_218_hpp
#define B_218_hpp


#include "../../Behaviour.hpp"

class B218: public Behaviour {
public:
	B218(): Behaviour(218,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		21800, // S-218-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_218_hpp */
