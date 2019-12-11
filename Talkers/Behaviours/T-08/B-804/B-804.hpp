//
//  B-804.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_804_hpp
#define B_804_hpp


#include "../../Behaviour.hpp"

class B804 : public Behaviour {
public:
	B804() : Behaviour(804,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80400 // S-804-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_804_hpp */
