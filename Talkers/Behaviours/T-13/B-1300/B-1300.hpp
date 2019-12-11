//
//  B-1300.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_1300_hpp
#define B_1300_hpp


#include "../../Behaviour.hpp"

class B1300 : public Behaviour {
public:
	B1300() : Behaviour(1300,	// ID
		13,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		130000 // S-1300-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		// vérifie si les interacteurs sont proches les uns des autres
		// CLOSE_ENCOUNTERS_WATCHER ;)))
		return true;
	}
};


#endif /* B_1300_hpp */
