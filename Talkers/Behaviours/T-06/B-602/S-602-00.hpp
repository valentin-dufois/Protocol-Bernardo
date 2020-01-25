//
//  S-602-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_602_00_hpp
#define S_602_00_hpp

#include "../../Output.hpp"

class S60200 : public Output {
public:

	S60200() : Output(60200,	// Output ID
		false,	// Is tree end ?
		603,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"Quelle donnée te permet de dire ça ?"
		}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_602_00_hpp */
