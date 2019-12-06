//
//  B-208.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_208_hpp
#define B_208_hpp


#include "../../Behaviour.hpp"

class B208: public Behaviour {
public:
	B208(): Behaviour(208,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20800, // S-208-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_208_hpp */
