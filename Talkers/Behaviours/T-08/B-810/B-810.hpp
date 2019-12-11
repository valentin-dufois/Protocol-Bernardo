//
//  B-810.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_810_hpp
#define B_810_hpp


#include "../../Behaviour.hpp"

class B810 : public Behaviour {
public:
	B810() : Behaviour(810,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81000 // S-810-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_810_hpp */
