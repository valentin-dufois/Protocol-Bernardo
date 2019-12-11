//
//  B-705.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_705_hpp
#define B_705_hpp


#include "../../Behaviour.hpp"

class B705 : public Behaviour {
public:
	B705() : Behaviour(705,	// ID
		7,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		70500 // S-705-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_705_hpp */