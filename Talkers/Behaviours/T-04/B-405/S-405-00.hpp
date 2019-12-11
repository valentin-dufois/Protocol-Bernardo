//
//  S-405-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_405_00_hpp
#define S_405_00_hpp

#include "../../Output.hpp"

class S40500 : public Output {
public:

	S40500() : Output(40500,	// Output ID
		false,	// Is tree end ?
		406,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"C'est probablement pour ça que nous travaillons à deux."
		}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_405_00_hpp */
