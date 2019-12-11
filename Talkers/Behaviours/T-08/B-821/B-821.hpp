//
//  B-821.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_821_hpp
#define B_821_hpp


#include "../../Behaviour.hpp"

class B821 : public Behaviour {
public:
	B821() : Behaviour(821,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		82100 // S-821-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_821_hpp */
