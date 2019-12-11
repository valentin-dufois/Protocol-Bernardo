//
//  S-808-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_808_00_hpp
#define S_808_00_hpp

#include "../../Output.hpp"

class S80800 : public Output {
public:

	S80800() : Output(80800,	// Output ID
		false,	// Is tree end ?
		809,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Certes."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_808_00_hpp */
