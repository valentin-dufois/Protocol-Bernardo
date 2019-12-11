//
//  B-825.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_825_hpp
#define B_825_hpp


#include "../../Behaviour.hpp"

class B825 : public Behaviour {
public:
	B825() : Behaviour(825,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		82500 // S-825-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_825_hpp */
