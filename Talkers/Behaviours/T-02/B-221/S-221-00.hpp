//
//  S-221-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_221_00_hpp
#define S_221_00_hpp

#include "../../Output.hpp"

class S22100: public Output {
public:

	S22100(): Output(22100,	// Output ID
					 true,	// Is tree end ?
					 -1,		// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"En effet."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_221_00_hpp */
