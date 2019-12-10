//
//  S-608-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_608_00_hpp
#define S_608_00_hpp

#include "../../Output.hpp"

class S60800 : public Output {
public:

	S60800() : Output(60800,	// Output ID
		false,	// Is tree end ?
		609,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"Il y a 2630 personnes dans la salle."
		}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_608_00_hpp */
