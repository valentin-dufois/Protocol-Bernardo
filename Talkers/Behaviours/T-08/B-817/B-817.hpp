//
//  B-817.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_817_hpp
#define B_817_hpp


#include "../../Behaviour.hpp"

class B817 : public Behaviour {
public:
	B817() : Behaviour(817,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81700 // S-817-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_817_hpp */
