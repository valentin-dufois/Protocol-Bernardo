//
//  B-701.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_701_hpp
#define B_701_hpp


#include "../../Behaviour.hpp"

class B701 : public Behaviour {
public:
	B701() : Behaviour(701,	// ID
		7,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		70100 // S-701-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_701_hpp */
