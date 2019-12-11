//
//  B-803.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_803_hpp
#define B_803_hpp


#include "../../Behaviour.hpp"

class B803 : public Behaviour {
public:
	B803() : Behaviour(803,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80300 // S-803-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_803_hpp */
