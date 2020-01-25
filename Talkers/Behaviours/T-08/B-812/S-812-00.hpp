//
//  S-812-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_812_00_hpp
#define S_812_00_hpp

#include "../../Output.hpp"

class S81200 : public Output {
public:

	S81200() : Output(81200,	// Output ID
		false,	// Is tree end ?
		813,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Peux-tu développer ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_812_00_hpp */
