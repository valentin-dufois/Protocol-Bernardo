//
//  S-510-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_510_00_hpp
#define S_510_00_hpp

#include "../../Output.hpp"

class S51000 : public Output {
public:

	S51000() : Output(51000,	// Output ID
		false,	// Is tree end ?
		511, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Il semblerait."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_510_00_hpp */
