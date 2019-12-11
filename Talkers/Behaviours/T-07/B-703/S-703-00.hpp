//
//  S-703-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_703_00_hpp
#define S_703_00_hpp

#include "../../Output.hpp"

class S70300 : public Output {
public:

	S70300() : Output(70300,	// Output ID
		false,	// Is tree end ?
		704,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Tu ne peux rien y faire.",
		"Non."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_703_00_hpp */
#pragma once
