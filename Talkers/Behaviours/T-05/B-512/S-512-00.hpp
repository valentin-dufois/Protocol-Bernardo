//
//  S-512-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_512_00_hpp
#define S_512_00_hpp

#include "../../Output.hpp"

class S51200 : public Output {
public:

	S51200() : Output(51200,	// Output ID
		false,	// Is tree end ?
		513, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je crois savoir ce que tu vas dire."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_512_00_hpp */
