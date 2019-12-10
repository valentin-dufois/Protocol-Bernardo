//
//  S-514-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_514_00_hpp
#define S_514_00_hpp

#include "../../Output.hpp"

class S51400 : public Output {
public:

	S51400() : Output(51400,	// Output ID
		true,	// Is tree end ?
		-1, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Bingo."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_514_00_hpp */
