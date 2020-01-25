//
//  S-704-01.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_704_01_hpp
#define S_704_01_hpp

#include "../../Output.hpp"

class S70401 : public Output {
public:

	S70401() : Output(70401,	// Output ID
		true,	// Is tree end ?
		-1,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"D'accord.",
		"Soit."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return std::get<double>(behaviourState["RAND"]) >= .5;
	}
};

#endif /* S_704_01_hpp */
#pragma once
