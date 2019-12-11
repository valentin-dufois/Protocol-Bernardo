//
//  S-406-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_406_00_hpp
#define S_406_00_hpp

#include "../../Output.hpp"

class S40600 : public Output {
public:

	S40600() : Output(40600,	// Output ID
		true,	// Is tree end ?
		-1,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Certes.",
		"Intéressant."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_406_00_hpp */
