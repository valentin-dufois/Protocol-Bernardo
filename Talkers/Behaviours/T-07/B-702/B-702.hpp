//
//  B-702.hpp
//  Talkers
//
//  Created by Marie-Lou on 2019-12-11.
//

#ifndef B_702_hpp
#define B_702_hpp


#include "../../Behaviour.hpp"

class B702 : public Behaviour {
public:
	B702() : Behaviour(702,	// ID
		7,		// Tree ID
		false,	// Is tree start ?
		true,	// Force start ?
		{		// Expected inputs

		},
					  {		// Expected outputs
		70200 // S-702-00
					  }) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_702_hpp */
