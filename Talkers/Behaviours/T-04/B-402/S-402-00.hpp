//
//  S-402-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_402_00_hpp
#define S_402_00_hpp

#include "../../Output.hpp"

class S40200 : public Output {
public:

	S40200() : Output(40200,	// Output ID
		false,	// Is tree end ?
		403,	// Next behaviour
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Peut-être. Nous serons probablement plus efficaces à deux.",
		"Il est fort probable que nous soyons plus efficaces."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_402_00_hpp */
