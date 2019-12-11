//
//  B-806.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_806_hpp
#define B_806_hpp


#include "../../Behaviour.hpp"

class B806 : public Behaviour {
public:
	B806() : Behaviour(806,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80600 // S-806-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_806_hpp */
