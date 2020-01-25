//
//  S-506-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_506_00_hpp
#define S_506_00_hpp

#include "../../Output.hpp"

class S50600 : public Output {
public:

	S50600() : Output(50600,	// Output ID
		false,	// Is tree end ?
		507, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Pourquoi donc ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_506_00_hpp */
