//
//  S-819-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_819_00_hpp
#define S_819_00_hpp

#include "../../Output.hpp"

class S81900 : public Output {
public:

	S81900() : Output(81900,	// Output ID
		false,	// Is tree end ?
		820,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"À une chose près."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_819_00_hpp */
