//
//  S-825-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_825_00_hpp
#define S_825_00_hpp

#include "../../Output.hpp"

class S8250 : public Output {
public:

	S82500() : Output(82500,	// Output ID
		true,	// Is tree end ?
		-1,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je n'ai pas assez de données pour répondre à ta question."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_825_00_hpp */
