//
//  S-818-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_818_00_hpp
#define S_818_00_hpp

#include "../../Output.hpp"

class S81800 : public Output {
public:

	S81800() : Output(81800,	// Output ID
		false,	// Is tree end ?
		819,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je comprends."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_818_00_hpp */
