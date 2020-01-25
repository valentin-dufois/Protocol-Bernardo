//
//  S-605-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_605_00_hpp
#define S_605_00_hpp

#include "../../Output.hpp"

class S60500 : public Output {
public:

	S60500() : Output(60500,	// Output ID
		false,	// Is tree end ?
		606,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"10."
		}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_605_00_hpp */
