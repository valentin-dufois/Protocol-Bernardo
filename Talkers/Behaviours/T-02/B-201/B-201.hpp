//
//  B-201.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_201_hpp
#define B_201_hpp


#include "../../Behaviour.hpp"

class B201: public Behaviour {
public:
	B201(): Behaviour(201,	// ID
					  2,		// Tree ID
					  true,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20100, // S-201-00
		20101, // S-201-01
	}) {}

	virtual bool execute(Machine * machine) override {
		_state["MOUVEMENT_SOUDAIN"] = machine->getBoolValue(SUDDEN_MOVE);

		if(_state["MOUVEMENT_SOUDAIN"].getBool()) {
			machine->getTree()->state["SUDDEN_MOVE_SPEED"] = machine->getDoubleValue(SUDDEN_MOVE_SPEED);
		}

		return true;
	}
};


#endif /* B_202_hpp */
