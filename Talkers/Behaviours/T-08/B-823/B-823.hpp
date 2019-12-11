//
//  B-823.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_823_hpp
#define B_823_hpp


#include "../../Behaviour.hpp"

class B823 : public Behaviour {
public:
	B823() : Behaviour(823,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		82300 // S-823-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_823_hpp */
