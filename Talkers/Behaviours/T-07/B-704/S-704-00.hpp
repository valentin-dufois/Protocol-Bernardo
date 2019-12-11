//
//  S-704-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_704_00_hpp
#define S_704_00_hpp

#include "../../Output.hpp"

class S70400 : public Output {
public:

	S70400() : Output(70400,	// Output ID
		false,	// Is tree end ?
		705,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Pouvez-vous reculer s'il-vous-plaît ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		// 50% chance of execution
		return true;
	};
};

#endif /* S_704_00_hpp */