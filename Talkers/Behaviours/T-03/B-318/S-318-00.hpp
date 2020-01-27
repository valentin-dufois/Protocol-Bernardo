//
//  S-318-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_318_00_hpp
#define S_318_00_hpp

#include "../../Output.hpp"

class S31800: public Output {
public:

	S31800(): Output(31800,	// Output ID
					 true,	// Is tree end ?
					 319,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Peut-être qu'elles aimeraient être seules."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_318_00_hpp */
