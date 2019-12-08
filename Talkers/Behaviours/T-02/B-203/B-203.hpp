//
//  B-203.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_203_hpp
#define B_203_hpp


#include "../../Behaviour.hpp"

class B203: public Behaviour {
public:
	B203(): Behaviour(203,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20300, // S-202-00
	}) {}

	virtual bool execute(Machine * machine) override {
		_state.insert_or_assign("SUDDEN_MOVE_SPEED", machine->getTree()->state.at("SUDDEN_MOVE_SPEED"));
		return true;
	}
};


#endif /* B_203_hpp */
