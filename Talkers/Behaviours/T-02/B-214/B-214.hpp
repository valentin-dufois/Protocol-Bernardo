//
//  B-214.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_214_hpp
#define B_214_hpp


#include "../../Behaviour.hpp"

class B214: public Behaviour {
public:
	B214(): Behaviour(214,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		21400, // S-214-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};

#endif /* B_214_hpp */
