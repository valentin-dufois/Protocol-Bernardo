//
//  S-609-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_609_00_hpp
#define S_609_00_hpp

#include "../../Output.hpp"

class S60900 : public Output {
public:

	S60900() : Output(60900,	// Output ID
		false,	// Is tree end ?
		610,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"C'est considérable."
		}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_609_00_hpp */
