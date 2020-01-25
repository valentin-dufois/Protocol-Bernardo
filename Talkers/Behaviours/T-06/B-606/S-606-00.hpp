//
//  S-606-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_606_00_hpp
#define S_606_00_hpp

#include "../../Output.hpp"

class S60600 : public Output {
public:

	S60600() : Output(60600,	// Output ID
		false,	// Is tree end ?
		607,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"Intéressant. Si je te donne un autre nombre, tu effectueras ce même processus ?"
		}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_606_00_hpp */
