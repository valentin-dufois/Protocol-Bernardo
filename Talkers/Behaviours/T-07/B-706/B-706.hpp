//
//  B-706.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_706_hpp
#define B_706_hpp


#include "../../Behaviour.hpp"

class B706 : public Behaviour {
public:
	B706() : Behaviour(706,	// ID
		7,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		70600 // S-706-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_706_hpp */
