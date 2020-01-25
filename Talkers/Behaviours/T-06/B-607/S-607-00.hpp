//
//  S-607-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_607_00_hpp
#define S_607_00_hpp

#include "../../Output.hpp"

class S60700 : public Output {
public:

	S60700() : Output(60700,	// Output ID
		false,	// Is tree end ?
		608,	// Next Behaviour ID
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

#endif /* S_607_00_hpp */
