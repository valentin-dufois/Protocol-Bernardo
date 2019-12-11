//
//  S-814-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_814_00_hpp
#define S_814_00_hpp

#include "../../Output.hpp"

class S81400 : public Output {
public:

	S81400() : Output(81400,	// Output ID
		false,	// Is tree end ?
		815,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je comprends."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_814_00_hpp */
