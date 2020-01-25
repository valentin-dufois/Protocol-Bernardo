//
//  S-701-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_701_00_hpp
#define S_701_00_hpp

#include "../../Output.hpp"

class S70100 : public Output {
public:

	S70100() : Output(70100,	// Output ID
		false,	// Is tree end ?
		702,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Oui ?",
		"Et alors ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_701_00_hpp */
