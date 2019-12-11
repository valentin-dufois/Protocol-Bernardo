//
//  S-811-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_811_00_hpp
#define S_811_00_hpp

#include "../../Output.hpp"

class S81100 : public Output {
public:

	S81100() : Output(81100,	// Output ID
		false,	// Is tree end ?
		812,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Pas un point d'arrivée."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_811_00_hpp */
