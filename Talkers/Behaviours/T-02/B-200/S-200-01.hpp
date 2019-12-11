//
//  S-200-01.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_200_01_hpp
#define S_200_01_hpp

#include "../../Output.hpp"

class S20001 : public Output {
public:

	S20001() : Output(20001,	// Output ID
		true,	// Is tree end ?
		900,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Il y a quelqu'un qui s'agite."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return behaviourState.at("RAND").getDouble() >= .33 &&
		behaviourState.at("RAND").getDouble() < .66;
	};
};

#endif /* S_200_00_hpp */
