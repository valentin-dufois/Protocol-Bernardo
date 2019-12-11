//
//  B-819.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_819_hpp
#define B_819_hpp


#include "../../Behaviour.hpp"

class B819 : public Behaviour {
public:
	B819() : Behaviour(819,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81900 // S-819-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_819_hpp */
