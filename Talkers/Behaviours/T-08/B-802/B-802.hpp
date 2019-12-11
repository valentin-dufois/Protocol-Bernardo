//
//  B-802.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_802_hpp
#define B_802_hpp


#include "../../Behaviour.hpp"

class B802 : public Behaviour {
public:
	B802() : Behaviour(802,	// ID
		8,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		80200 // S-802-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_802_hpp */
