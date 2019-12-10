//
//  S-503-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_503_00_hpp
#define S_503_00_hpp

#include "../../Output.hpp"

class S50300 : public Output {
public:

	S50300() : Output(50300,	// Output ID
		false,	// Is tree end ?
		504, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je ne crois pas. Je n'ai pas plus de donnée que toi."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_503_00_hpp */
