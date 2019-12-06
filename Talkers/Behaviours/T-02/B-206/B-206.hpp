//
//  B-206.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_206_hpp
#define B_206_hpp


#include "../../Behaviour.hpp"

class B206: public Behaviour {
public:
	B206(): Behaviour(206,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20600, // S-206-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_206_hpp */
