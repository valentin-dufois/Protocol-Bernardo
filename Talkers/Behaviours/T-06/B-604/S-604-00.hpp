//
//  S-604-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_604_00_hpp
#define S_604_00_hpp

#include "../../Output.hpp"

class S60400 : public Output {
public:

	S60400() : Output(60400,	// Output ID
		false,	// Is tree end ?
		605,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"Quel est ce seuil ?"
		}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_604_00_hpp */
