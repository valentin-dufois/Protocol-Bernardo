//
//  S-613-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_613_00_hpp
#define S_613_00_hpp

#include "../../Output.hpp"

class S61300 : public Output {
public:

	S61300() : Output(61300,	// Output ID
		true,	// Is tree end ?
		-1,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"Probablement."
		}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_613_00_hpp */
