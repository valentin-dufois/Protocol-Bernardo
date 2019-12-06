//
//  B-210.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_210_hpp
#define B_210_hpp


#include "../../Behaviour.hpp"

class B210: public Behaviour {
public:
	B210(): Behaviour(210,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		21000, // S-210-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_210_hpp */
