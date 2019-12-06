//
//  B-219.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_219_hpp
#define B_219_hpp


#include "../../Behaviour.hpp"

class B219: public Behaviour {
public:
	B219(): Behaviour(219,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		21900, // S-219-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_219_hpp */
