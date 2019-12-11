//
//  B-815.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_815_hpp
#define B_815_hpp


#include "../../Behaviour.hpp"

class B815 : public Behaviour {
public:
	B815() : Behaviour(815,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		81500 // S-815-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_815_hpp */
