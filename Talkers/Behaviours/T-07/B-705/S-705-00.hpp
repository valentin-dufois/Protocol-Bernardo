//
//  S-705-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_705_00_hpp
#define S_705_00_hpp

#include "../../Output.hpp"

class S70500 : public Output {
public:

	S70500() : Output(70500,	// Output ID
		true,	// Is tree end ?
		706,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Qu'est-ce que tu fais ?",
		"Qu'est-ce qui t'arrives ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_705_00_hpp */
