//
//  B-1301.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_1301_hpp
#define B_1301_hpp


#include "../../Behaviour.hpp"

class B1301 : public Behaviour {
public:
	B1301() : Behaviour(1301,	// ID
		13,		// Tree ID
		true,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		130100 // S-1301-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_1301_hpp */
