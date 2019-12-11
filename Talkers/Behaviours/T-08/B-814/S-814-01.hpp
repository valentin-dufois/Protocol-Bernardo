//
//  S-814-01.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_814_01_hpp
#define S_814_01_hpp

#include "../../Output.hpp"

class S81401 : public Output {
public:

	S81401() : Output(81401,	// Output ID
		false,	// Is tree end ?
		823,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Peut-tre sont-elles toujours les mmes."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return behaviourState.at("RAND").getDouble() >= .5;
	};
};

#endif /* S_814_01_hpp */
