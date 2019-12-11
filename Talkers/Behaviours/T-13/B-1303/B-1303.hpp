//
//  B-1303.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_1303_hpp
#define B_1303_hpp


#include "../../Behaviour.hpp"

class B1303 : public Behaviour {
public:
	B1303() : Behaviour(1303,	// ID
		13,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		130300 // S-1303-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_1303_hpp */
