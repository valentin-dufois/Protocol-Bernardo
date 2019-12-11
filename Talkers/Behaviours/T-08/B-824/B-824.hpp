//
//  B-824.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_824_hpp
#define B_824_hpp


#include "../../Behaviour.hpp"

class B824 : public Behaviour {
public:
	B824() : Behaviour(824,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		82400 // S-824-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_824_hpp */
