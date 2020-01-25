//
//  S-816-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_816_00_hpp
#define S_816_00_hpp

#include "../../Output.hpp"

class S81600 : public Output {
public:

	S81600() : Output(81600,	// Output ID
		false,	// Is tree end ?
		817,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"En effet."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_816_00_hpp */
