//
//  S-315-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_315_00_hpp
#define S_315_00_hpp

#include "../../Output.hpp"

class S31500: public Output {
public:

	S31500(): Output(31500,	// Output ID
					 false,	// Is tree end ?
					 316,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Dommage."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_315_00_hpp */
