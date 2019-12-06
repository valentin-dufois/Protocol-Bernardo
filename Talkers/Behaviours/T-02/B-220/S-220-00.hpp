//
//  S-220-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_220_00_hpp
#define S_220_00_hpp

#include "../../Output.hpp"

class S22000: public Output {
public:

	S22000(): Output(22000,	// Output ID
					 true,	// Is tree end ?
					 221,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Fascinant."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_220_00_hpp */
