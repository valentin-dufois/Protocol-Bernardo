//
//  S-505-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_505_00_hpp
#define S_505_00_hpp

#include "../../Output.hpp"

class S50500 : public Output {
public:

	S50500() : Output(50500,	// Output ID
		false,	// Is tree end ?
		506, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Oui. Mais je ne peux pas y répondre avec certitude."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_505_00_hpp */
