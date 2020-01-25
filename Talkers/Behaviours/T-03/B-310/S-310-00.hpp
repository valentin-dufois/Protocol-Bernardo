//
//  S-310-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_310_00_hpp
#define S_310_00_hpp

#include "../../Output.hpp"

class S31000: public Output {
public:

	S31000(): Output(31000,	// Output ID
					 false,	// Is tree end ?
					 311,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Oui."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_310_00_hpp */
