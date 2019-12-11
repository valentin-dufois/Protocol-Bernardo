//
//  B-902.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_902_hpp
#define B_902_hpp


#include "../../Behaviour.hpp"

class B902 : public Behaviour {
public:
	B902() : Behaviour(902,	// ID
		9,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		90200 // S-902-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_902_hpp */
