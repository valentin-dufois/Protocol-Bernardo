//
//  S-820-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_820_00_hpp
#define S_820_00_hpp

#include "../../Output.hpp"

class S82000 : public Output {
public:

	S82000() : Output(82000,	// Output ID
		false,	// Is tree end ?
		821,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Laquelle ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_820_00_hpp */
