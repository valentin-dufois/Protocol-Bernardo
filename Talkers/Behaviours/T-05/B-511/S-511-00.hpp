//
//  S-511-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_511_00_hpp
#define S_511_00_hpp

#include "../../Output.hpp"

class S51100 : public Output {
public:

	S51100() : Output(51100,	// Output ID
		false,	// Is tree end ?
		512, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Une question demeure."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_511_00_hpp */
