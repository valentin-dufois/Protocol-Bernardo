//
//  S-702-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_702_00_hpp
#define S_702_00_hpp

#include "../../Output.hpp"

class S70200 : public Output {
public:

	S70200() : Output(70200,	// Output ID
		false,	// Is tree end ?
		703,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je devrais faire quelque chose ?",
		"Ce n'est pas alarmant ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_702_00_hpp */
