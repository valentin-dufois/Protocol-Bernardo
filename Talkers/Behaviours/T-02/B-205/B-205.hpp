//
//  B-205.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_205_hpp
#define B_205_hpp


#include "../../Behaviour.hpp"

class B205: public Behaviour {
public:
	B205(): Behaviour(205,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20500, // S-205-00
	}) {}

	virtual bool execute(Machine * machine) override {
		_state.insert_or_assign("SUDDEN_MOVE_SPEED_TIMES_FROM_AVERAGE", machine->getTree()->state.at("SUDDEN_MOVE_SPEED").getDouble() / machine->arena()->averageMoveSpeed());
		return true;
	}
};


#endif /* B_205_hpp */
