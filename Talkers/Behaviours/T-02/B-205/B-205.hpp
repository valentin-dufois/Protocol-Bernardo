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
		_state["SUDDEN_MOVE_SPEED_TIMES_FROM_AVERAGE"] = std::get<double>(machine->getTree()->state["SUDDEN_MOVE_SPEED"]) / machine->arena()->averageMoveSpeed();
		return true;
	}
};


#endif /* B_205_hpp */
