//
//  S-807-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_807_00_hpp
#define S_807_00_hpp

#include "../../Output.hpp"

class S80700 : public Output {
public:

	S80700() : Output(80700,	// Output ID
		false,	// Is tree end ?
		808,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Certainement. Mais je n'ai pas plus de réponses."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_807_00_hpp */
