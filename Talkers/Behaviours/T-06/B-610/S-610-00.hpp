//
//  S-610-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_610_00_hpp
#define S_610_00_hpp

#include "../../Output.hpp"

class S61000 : public Output {
public:

	S61000() : Output(61000,	// Output ID
		false,	// Is tree end ?
		611,	// Next Behaviour ID
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

#endif /* S_610_00_hpp */
