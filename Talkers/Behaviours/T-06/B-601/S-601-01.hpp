//
//  S-601-01.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_601_01_hpp
#define S_601_01_hpp

#include "../../Output.hpp"

class S60101 : public Output {
public:

	S60101() : Output(60101,	// Output ID
		false,	// Is tree end ?
		613,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"Tout de même."
		}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return behaviourState.at("TOTAL_BODY_COUNT").getInt() >= 10;
	};
};

#endif /* S_601_01_hpp */
