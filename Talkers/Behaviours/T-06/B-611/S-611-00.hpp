//
//  S-611-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_611_00_hpp
#define S_611_00_hpp

#include "../../Output.hpp"

class S61100 : public Output {
public:

	S61100() : Output(61100,	// Output ID
		false,	// Is tree end ?
		612,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"C'est aussi un mensonge."
		}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_611_00_hpp */
