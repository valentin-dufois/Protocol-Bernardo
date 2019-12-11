//
//  B-814.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_814_hpp
#define B_814_hpp


#include "../../Behaviour.hpp"

class B814 : public Behaviour {
public:
	B814() : Behaviour(814,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81400 // S-814-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_814_hpp */
