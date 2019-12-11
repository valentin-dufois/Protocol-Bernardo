//
//  B-1302.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_1302_hpp
#define B_1302_hpp


#include "../../Behaviour.hpp"

class B1302 : public Behaviour {
public:
	B1302() : Behaviour(1302,	// ID
		13,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		130200 // S-1302-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_1302_hpp */
