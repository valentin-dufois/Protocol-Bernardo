//
//  B-209.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_209_hpp
#define B_209_hpp


#include "../../Behaviour.hpp"

class B209: public Behaviour {
public:
	B209(): Behaviour(209,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20900, // S-209-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_209_hpp */
