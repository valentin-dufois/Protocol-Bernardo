//
//  S-403-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_403_00_hpp
#define S_403_00_hpp

#include "../../Output.hpp"

class S40300 : public Output {
public:

	S40300() : Output(40300,	// Output ID
		false,	// Is tree end ?
		404,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Certainement. Quelle est ta question ?",
		"C'est surement le cas. Quelle était ta question ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_403_00_hpp */
