//
//  B-901.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_901_hpp
#define B_901_hpp


#include "../../Behaviour.hpp"

class B901 : public Behaviour {
public:
	B901() : Behaviour(901,	// ID
		9,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		90100 // S-901-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_901_hpp */
