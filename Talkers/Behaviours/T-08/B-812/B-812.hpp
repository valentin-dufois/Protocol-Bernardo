//
//  B-812.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_812_hpp
#define B_812_hpp


#include "../../Behaviour.hpp"

class B812 : public Behaviour {
public:
	B812() : Behaviour(812,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81200 // S-812-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_812_hpp */
